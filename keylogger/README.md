#  Keylogger en C

##  Descripción  

Este proyecto es un keylogger simple escrito en C. Un keylogger es una herramienta que registra las pulsaciones de teclas de un usuario en un archivo de registro. Este proyecto está destinado únicamente para fines educativos y de seguridad, y no debe usarse para actividades malintencionadas o ilegales.

##  Características  

-  Registro de todas las pulsaciones de teclas.

-  Guarda las pulsaciones en un archivo de registro.

-  Funciona en segundo plano.

##  Requisitos  

-  Sistema operativo Windows.

-  Compilador GCC para Windows (MinGW recomendado).

##  Instalación  

1.  **Instalar MinGW:**

-  Descarga e instala MinGW desde [MinGW](http://www.mingw.org/).

-  Durante la instalación, asegúrate de seleccionar `msys-base` y `gcc`.

2.  **Clonar el repositorio:**  

```sh
	git  clone  https://github.com/tu_usuario/keylogger-en-c.git

	cd  keylogger-en-c
```

## Notas:
 Asegúrate de tener libxkbcommon instalada. Puedes instalarla con:
```sh
sudo apt-get install libxkbcommon-dev
```

##  Compilar el keylogger:
Abre la terminal de MinGW y navega al directorio del proyecto, asegurándote de enlazar con libxkbcommon. Luego, ejecuta:

```sh
	gcc keylogger.c -o keylogger -lxkbcommon
```

##  Uso

1.  Ejecutar el keylogger:
```sh
./keylogger.exe
```

2.  Ver el archivo de registro:
Las pulsaciones de teclas se guardarán en un archivo llamado keylog.txt en el mismo directorio donde se ejecuta el keylogger.

##  Casos de Uso

1.  **Seguridad y Auditoría**
Los administradores del sistema pueden usar este keylogger para monitorear el uso del teclado en una máquina específica para detectar posibles usos no autorizados.

2.  **Estudios de Usabilidad**
Los desarrolladores de software pueden utilizar este keylogger para estudiar cómo los usuarios interactúan con su software y mejorar la experiencia del usuario.

3.  **Recuperación de Datos**
En situaciones donde se requiere recuperar texto escrito pero no guardado debido a una falla del sistema, un keylogger puede ser útil.

4.  **Fines Educativos**

Este proyecto sirve como una herramienta educativa para aprender sobre la captura de eventos del sistema y la programación de bajo nivel en C.

**Advertencia**

Este software se proporciona con fines educativos y de seguridad. El uso indebido de este software, como la captura de pulsaciones de teclas sin el consentimiento del usuario, es ilegal y puede resultar en severas consecuencias legales. Utilice este software bajo su propia responsabilidad y asegúrese de cumplir con todas las leyes y regulaciones aplicables.

**Contribuciones**

Las contribuciones son bienvenidas. Por favor, haga un fork del repositorio y envíe un pull request con sus mejoras.