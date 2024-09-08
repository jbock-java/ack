#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
  return a < b ? b : a;
}

int ackermann(long m, long n) {
  long next[m + 1];
  long goal[m + 1];
  for (int s = 0; s < m; s++) {
    next[s] = 0;
    goal[s] = 1;
  }
  next[m] = 0;
  goal[m] = -1;
  do {
    long value = next[0] + 1;
    bool transferring = true;
    int mm = 0;
    while (transferring) {
      if (next[mm] == goal[mm]) {
        goal[mm] = value;
      } else {
        transferring = false;
      }
      next[mm]++;
      mm++;
    }
  } while (next[m] != n + 1);
  return next[0];
}

int stackermann(long mm, long nn) {
  int length = 2;
  int size = 120000 * mm;
  int maxstack = 2;
  long stack[size];
  stack[0] = mm;
  stack[1] = nn;
  while (length != 1) {
    long m = stack[length - 2];
    long n = stack[length - 1];
    #ifdef DEBUG
    for (int i = 0; i < length; i++) {
      printf("%d ", stack[i]);
    }
    printf("\n");
    #endif
    if (m == 0) {
      stack[length - 2] = n + 1;
      length--;
    } else if (n == 0) {
      stack[length - 2] = m - 1;
      stack[length - 1] = 1;
    } else {
      stack[length - 2] = m - 1;
      stack[length - 1] = m;
      stack[length] = n - 1;
      length++;
      if (length == size) {
        printf("stack overflow\n");
        return -1;
      }
      if (length > maxstack) {
        maxstack = length;
      }
    }
  }
  printf("max stack: %d\n", maxstack);
  return stack[0];
}

int main(int argc, char **argv) {
  char* end;
  long m = strtol(argv[1], &end, 10);
  long n = strtol(argv[2], &end, 10);
  long result = ackermann(m, n);
  printf("ackermann(%d, %d) = %d\n", m, n, result);
//  result = stackermann(m, n);
//  printf("stackermann(%d, %d) = %d\n", m, n, result);
  return 0;
}