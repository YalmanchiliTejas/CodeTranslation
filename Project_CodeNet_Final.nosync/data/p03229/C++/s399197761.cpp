#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main(int argc, char* argv[])
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  sort(ALL(a));

  vector<ll> b(n, 0);
  int base = n / 2;
  b[base] = a[0];
  for (int i = 1; i <= n / 2; i++) {
    if (i%2 == 0) {
      b[base - i] = a[i-1];
      if (base +i >= n) break;
      b[base + i] = a[i];
    } else {
      b[base - i] = a[n-i];
      if (base +i >= n) break;
      b[base + i] = a[n-i-1];
    }
  }
/*
  rep(i, n) {
    cerr << b[i] << " ";
  }
  cerr << endl;
*/
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += abs(b[i] - b[i-1]);
  }

  // 逆から
  b[base] = a[n-1];
  for (int i = 1; i <= n / 2; i++) {
    if (i%2 == 0) {
      b[base - i] = a[n-i];
      if (base +i >= n) break;
      b[base + i] = a[n-i-1];
    } else {
      b[base - i] = a[i-1];
      if (base +i >= n) break;
      b[base + i] = a[i];
    }
  }
/*
  rep(i, n) {
    cerr << b[i] << " ";
  }
  cerr << endl;
*/
  ll ans2 = 0;
  for (int i = 1; i < n; i++) {
    ans2 += abs(b[i] - b[i-1]);
  }

  cout << max(ans, ans2) << endl;

  return 0;
}
