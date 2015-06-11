#include <getopt.h>
#include <stdio.h>
//#include <string.h>
#include <time.h>


int main(int argc, char **argv) {
  char option_character = 0;
  char *break_charachter = "";
  char *separator_charachter = ":";
  unsigned int i = 1;
  char usage[256];

  snprintf(usage, sizeof usage, "%s\n %s\n %s\n %s\n\n",
    "Usage: %s <options>\nOptions:",
    "-h\t\tprint help and exit",
    "-n\t\tadd line break",
    "-s [SEPARATOR]\tspecify separator (':' by default)"
  );


  while ((option_character = getopt(argc, argv, "nhs:")) != -1) {
    switch (option_character) {
    case 'h':
      fprintf(stderr, usage, argv[0]);
      return 1;
      break;
    case 'n':
      break_charachter = "\n";
      break;
    case 's':
      separator_charachter = optarg;
      break;
    default:
      return 1;
    }
  }

  srandom(time(NULL));
  printf("%02x", (random() % 255) & 0xfc);
  for (i; i < 6; i++) {
    if (i < 6) printf(separator_charachter);
    printf("%02x", random() % 255);
  };

  printf(break_charachter);
  return 0;
}
