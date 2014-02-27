/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  adler32 calc program
 *
 *        Version:  1.0
 *        Created:  02/27/2014 12:22:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darwin 
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t fadler32(FILE *fp);

int main(int argc, char **argv)
{
  if(argc < 2) {
    fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
    exit(1);
  }

  FILE *fp;
  fp = fopen(argv[1], "r");

  printf("Checksum for %s: %x\n", argv[1], fadler32(fp));

  return 0;
}

uint32_t fadler32(FILE *fp)
{
  int i;
  int c;
  uint32_t a = 1, b = 0;


  while((c = fgetc(fp)) != EOF) {
    a = (a + c) % 65521;
    b = (b + a) % 65521;
  }

  return (b << 16) | a;
}


