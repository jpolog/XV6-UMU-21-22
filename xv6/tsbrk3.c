#include "types.h"
#include "fcntl.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int fh = open ("README", O_RDONLY);

  char* a = sbrk (15000);

  read (fh, a+8192, 50);

  // Debe imprimir los 50 primeros caracteres de README
  printf (1, "Debe imprimir los 50 primeros caracteres de README:\n");
  printf (1, "%s\n", a+8192);

  close (fh);

  exit(0);
}


// Provoca fallo en el sistema operativo con un numero muy grande de paginas. No es fallo nuestro sino del sistema operativo porque hace que acceda a una pagina a la que no puede o algo así
