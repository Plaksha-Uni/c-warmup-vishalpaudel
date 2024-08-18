#include <cctype>
#include <cstdlib>
#include <cstdio>

enum ReadingMode {
  word,
  space
};

int main(void) {
  unsigned long lc = 0, wc = 0, bc = 0;
  char cur = fgetc(stdin);
  ReadingMode mode = space;
  while (cur != EOF) {
    if (cur == '\n') lc+=1;
    switch (mode) {
      case space: {
          if (!isspace(cur)) mode = word;
      }; break;
      case word: {
          if (isspace(cur)) { mode = space; wc+=1; }
      }; break;
    }
    bc+=1;
    cur = fgetc(stdin);
  }
  fprintf(stdout, "%8lu%8lu%8lu\n", lc, wc, bc);
}
