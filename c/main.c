#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main() {
  long int *vec = (long int *) malloc(sizeof(long int) * 10);
  vec[0] = 1;
  vec[1] = 1;
  vec[2] = 1;
  vec[3] = 1;
  long int *ptr = &vec[3];

  long int *vec_dummy = (long int *) malloc(sizeof(long int) * 10);

  printf("Before realloc: %016lx\n", (unsigned long int) ptr);
  puts("Realloc");
  // realloc!
  vec = (long int *) realloc((void *) vec, sizeof(long int) * 100);
  printf("After realloc ptr addr: %016lx\n", (unsigned long int) ptr);
  printf("After realloc addr: %016lx\n", (unsigned long int) &vec[3]);
  assert(ptr != &vec[3]);
}
