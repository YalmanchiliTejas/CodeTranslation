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
const double pi = acos(-1.0);

LL n, k, l1, l2, r1, r2;

int main() {
#ifdef LOCAL
  auto start_clock = clock();
  freopen("in", "r", stdin);
#endif

  int x;
  scanf("%d", &x);
  if (x >= 30) puts("Yes");
  else puts("No");

#ifdef LOCAL
 auto end_clock = clock();
 cout << "Time:" << (end_clock - start_clock) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}