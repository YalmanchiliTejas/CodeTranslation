#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; i++)
#define why(n, x)                                                              \
  int n;                                                                       \
  while (cin >> n, n != x)
#define iFOR(i, x, n) for (int i = x; i < n; i++)
#define fin << '\n'
#define __ << " " <<
#define ___ << " "
#define bash push_back
#define ALL(x) x.begin(), x.end()
#define SWAP(a, b) ((a != b) && (a += b, b = a - b, a -= b))
//#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vit;
typedef map<string, int> mstit;
typedef vector<pii> vpi;
typedef greater<pii> gpi;
typedef priority_queue<pii, vpi, gpi> dijk;
static const signed int INF = 0x3f3f3f3f;
static const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static const signed int SMOD = 1000000007;
static const signed int NMOD = 1000000009;
static const signed int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
static const signed int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

bool inside(int x, int y, int w, int h) {
  return (x >= 0 && y >= 0 && x < w && y < h);
}
template <class T> T abs(T &x) { return x < 0 ? -x : x; }
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int qp(int a, ll b, int mo) {
  int ans = 1;
  do {
    if (b & 1)
      ans = 1ll * ans * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return ans;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

ll bug[55], ps[55];

ll dp(ll i, ll j) {
  if (!i)
    return 1;
  if (j == 1)
    return 0;
  if (bug[i] == j)
    return ps[i];
  if (j == bug[i - 1] + 2)
    return ps[i - 1] + 1;
  if (j < bug[i - 1] + 2)
    return dp(i - 1, j - 1);
  return ps[i - 1] + 1 + dp(i - 1, j - bug[i - 1] - 2);
}

inline void solve() {

  ll n, x;

  cin >> n >> x;

  bug[0] = ps[0] = 1;

  for (int i = 1; i <= n; i++) {
    bug[i] = bug[i - 1] * 2 + 3;
    ps[i] = ps[i - 1] * 2 + 1;
  }

  cout << dp(n, x) << endl;
}
struct xyz {
  xyz() {
    cin.tie(0), ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
  };
} xyzzy;
signed main() {
  solve();
  return 0;
}
