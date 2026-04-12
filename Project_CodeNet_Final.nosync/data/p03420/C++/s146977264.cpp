#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF (long) 1e18
#define MOD 1'000'000'007
#define mll map<long, long>
#define pll pair<long, long>
#define umap unordered_map
#define umll umap<long, long>
#define uset unordered_set
#define pb push_back
#define FOR(i, a, b) \
  for (long i = (a); i < (long) (b); i++)
#define PRINTV(v) \
  FOR (_i, 0, v.size()) \
    cout << v[_i] << " "; \
  cout << "\n";

int main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  long n, k;
  cin >> n >> k;

  if (k == 0) {
    printf("%lld\n", n*n);
    return 0;
  }
  long total = 0;
  FOR (b, k+1, n+1) {
    long l = b;
    long x = ceil(double(n) / b);
    long r = l + b * (x-1);
    long y = x * (b - k);
    if (r > n+1) y -= r - max(n+1, r - (b-k));
    //printf("%lld: %lld\n", b, y);
    total += y;
  }
  printf("%lld\n", total);
}
