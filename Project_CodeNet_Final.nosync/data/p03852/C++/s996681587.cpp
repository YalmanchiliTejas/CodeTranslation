
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void) {
  char ch = getchar();
  puts(ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' ? "vowel" : "consonant");
  return 0;
}
