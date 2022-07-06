#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define EXPECTED_PID 1
#define EXPECTED_PPID 0

int main(int argc, char *argv[]) {
  if (getpid() != EXPECTED_PID) {
    fprintf(stderr, "permission denied\n");
    exit(EXIT_FAILURE);
  }

  if (getppid() != EXPECTED_PPID) {
    fprintf(stderr, "permission denied\n");
    exit(EXIT_FAILURE);
  }

  if (! (argc > 1)) {
    fprintf(stderr, "arguments expected\n");
    exit(EXIT_FAILURE);
  }

  if (setuid(atoi(argv[1])) != 0) {
    fprintf(stderr, "setuid error %d\n", errno);
    exit(EXIT_FAILURE);
  }

  execv(argv[2], &argv[2]);

  fprintf(stderr, "execv error %d\n", errno);
  exit(EXIT_FAILURE);
}
