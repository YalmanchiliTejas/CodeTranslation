#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) 0
#endif

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;

  if (m < n) {
  	puts("No");
   
  } else {
  	puts("Yes");
  }

  return 0;
}