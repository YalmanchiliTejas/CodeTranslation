#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  char s[1111];
  scanf("%s", s);

  int len = strlen(s);
  REP(i, len-1) if (s[i] == 'A' && s[i+1] == 'C') { puts("Yes"); return 0; }
  puts("No");
  return 0;
}
