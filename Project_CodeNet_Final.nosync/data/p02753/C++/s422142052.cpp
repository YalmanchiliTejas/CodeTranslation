#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const double TL = 1.5 * CLOCKS_PER_SEC;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define clr(x, y) memset(x, y, sizeof(x))
#define forn(i, n) for (int i = 0; i < n; i++)
#define LL long long

const int inf = 1e9;

char s[10];

int main() {
  //auto start_clock = clock();
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int a = 0, b = 0;
  scanf("%s", s);
  for(int i = 0; i < 3; i++) {
    if(s[i] == 'A') a += 1;
    else b += 1;
  }
  if(a > 0 && b > 0) puts("Yes");
  else puts("No");

  return 0;
}