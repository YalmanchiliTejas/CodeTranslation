#include <cstdio>
#include <iostream>
#include <algorithm>

// Definitions
#define MAXN
#define elif else if
typedef long long int64;
typedef long double num128;
typedef unsigned long long uint64;

// Variables
int n;

// Improve the speed of read-in.
inline bool IsNum(char x) { return ('0' <= x) && (x <= '9'); }
inline int64 ReadNum() {
  int64 sign = 1, val = 0; char tmp = getchar();
  while (!IsNum(tmp)) { if (tmp == '-') {sign = -sign;} tmp = getchar(); }
  while (IsNum(tmp)) { val = val * 10 + tmp - 48; tmp = getchar(); }
  return val * sign;
}

// Functions
inline void ReadIn() {
  n = ReadNum();
}
inline void PrintAns() {
  if (n >= 30) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  ReadIn();
  PrintAns();
  return 0;
}
/*

*/
