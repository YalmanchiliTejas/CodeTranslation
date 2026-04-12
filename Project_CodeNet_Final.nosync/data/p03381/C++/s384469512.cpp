#ifdef DBG1
  #define LOCAL
#endif

#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

bool solve() {
  int n;
  if (scanf("%d", &n) != 1) { return false; }

  vector <pii> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vector <int> num(n);
  for (int i = 0; i < n; ++i) {
    num[a[i].second] = i;
  }

  for (int i = 0; i < n; ++i) {
    int k = (0 + n - 2) / 2;
    if (k >= num[i]) {
      k++;
    }
    printf("%d\n", a[k].first);
  }

  return true;
}

int main() {
  while (solve());
  return 0;
}