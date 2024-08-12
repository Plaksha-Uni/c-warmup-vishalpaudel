#include <cstdio>

int main() {
  unsigned long bc = 0;
  while (fgetc(stdin) != EOF) {
    ++bc;
  }
  fprintf(stdout, "%8lu\n", bc);
}
