#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
using namespace std;

const int N = 3030, MOD = 998244353;
int n, s, a[N];
int ways[N];
int add(int a, int b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}
int main() {
  scanf ("%d%d", &n, &s);
  for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);

  int ans = 0;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = s; j >= a[i]; --j) ways[j] = add(ways[j], ways[j - a[i]]);
    ways[a[i]] = add(ways[a[i]], i);
    ans = add(ans, ways[s]);
  }
  cout << ans << endl;
}
