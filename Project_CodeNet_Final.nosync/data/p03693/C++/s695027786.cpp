#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for (ll i = (begin); i < (end); i++)
#define REP(i, n) FOR(i, 0, n)
#define IFOR(i, begin, end) for (ll i = (begin)-1; i >= (end); i--)
#define IREP(i, n) IFOR(i, n, 0)
#define SORT(a) sort(a.begin(), a.end())
#define ISORT(a) sort(a.begin(), a.end(), greater<ll>())
#define REVERSE(a) reverse(a.begin(), a.end())
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v)                                                              \
  cout << #v << "=(" << v[0];                                                  \
  FOR(i_debug, 1, v.size()) { cout << "," << v[i_debug]; }                     \
  cout << ")" << endl;
#define mdebug(m)                                                              \
  cout << #m << "=" << endl;                                                   \
  REP(i_debug, m.size()) {                                                     \
    REP(j_debug, m[i_debug].size()) { cout << m[i_debug][j_debug] << ","; }    \
    cout << endl;                                                              \
  }
#define Lower_bound(v, x)                                                      \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x)                                                      \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define INF 1000000000000000000

using vec = vector<ll>;
using mat = vector<vec>;
using Pii = pair<ll, ll>;
using PiP = pair<ll, Pii>;
using PPi = pair<Pii, ll>;
using bvec = vector<bool>;
using Pvec = vector<Pii>;

template <typename T> void readv(vector<T> &a) { REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a) {
  REP(i, a.size()) {
    cin >> a[i];
    a[i]--;
  }
}

ll mod = 1000000007;

int main() {
  ll r, g, b;
  cin >> r >> g >> b;

  ll ans = r * 100 + g * 10 + b;

  if (ans % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}