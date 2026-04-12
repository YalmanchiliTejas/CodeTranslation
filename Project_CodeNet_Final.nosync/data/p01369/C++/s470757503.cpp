#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int type[300];
char str[1000];
int main() {
  type[(int)'q'] = 1;
  type[(int)'w'] = 1;
  type[(int)'e'] = 1;
  type[(int)'r'] = 1;
  type[(int)'t'] = 1;
  type[(int)'a'] = 1;
  type[(int)'s'] = 1;
  type[(int)'d'] = 1;
  type[(int)'f'] = 1;
  type[(int)'g'] = 1;
  type[(int)'z'] = 1;
  type[(int)'x'] = 1;
  type[(int)'c'] = 1;
  type[(int)'v'] = 1;
  type[(int)'b'] = 1;
  while (scanf("%s", str), str[0] != '#') {
    int cnt = 0;
    int prev = type[(int)str[0]];
    int len = strlen(str);
    REP(i, len) {
      if (prev != type[(int)str[i]]) {
        cnt++;
      }
      prev = type[(int)str[i]];
    }
    printf("%d\n", cnt);
  }
}