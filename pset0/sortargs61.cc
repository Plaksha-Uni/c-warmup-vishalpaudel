#include <algorithm>
#include <cstdio>
#include <cstring>

void insertion_sort(int argc, char **argv) {
  for (int argi = 1; argi < argc; argi++) {
    for (int inneri = argi;
         inneri > 0 && strcmp(argv[inneri - 1], argv[inneri]) > 0;
         inneri -= 1) {
      std::swap(argv[inneri - 1], argv[inneri]);
    }
  }
}

void sortargs61_cstyle(int argc, char **argv) {
  if (argc <= 1) {
    return;
  }

  insertion_sort(argc, argv);

  for (int argi = 0; argi < argc; argi++) {
    printf("%s\n", argv[argi]);
  }
}

auto main(int argc, char **argv) -> int {
  sortargs61_cstyle(argc, argv);
  return 0;
}
