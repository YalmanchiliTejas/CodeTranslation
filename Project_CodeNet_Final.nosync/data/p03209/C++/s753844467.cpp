#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 53;

long long x, total[N], patties[N];

long long count(long long n, long long pos = 1) {
  if (n == 0) return pos <= x;
  long long ret = 0; ++pos;
  if (total[n-1] + pos > x) return ret + count(n-1, pos);
  pos += total[n-1]; ret += patties[n-1];
  if (pos > x) return ret;
  ++ret; ++pos;
  if (total[n-1] + pos > x) return ret + count(n-1, pos);
  return ret + patties[n-1];
}

void solve() {
  total[0] = 1;
  patties[0] = 1;
  for (int i = 1; i < N; ++i) {
    total[i] = total[i-1]*2+3;
    patties[i] = patties[i-1]*2+1;
  }
  long long n; scanf("%lld%lld", &n, &x);
  printf("%lld", count(n));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
