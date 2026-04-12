#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 10;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { rep(i, sz(v)) { if (i) os << " "; os << v[i]; } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
inline int add(int a, int b) { a += b; if (a >= mod) return a - mod; return a; }

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    // cin >> T;
    T = 1;

    while (T--) {
        solve();
    }
}


void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];

  ll ans = 0;
  rep3(c, 1, n) { // 座標は0 ~ n-1
    ll tmp = 0;
    int flg = 0;
    set<int> st;
    rep(x, n) {
      int a = (n - 1) - x * c; // どんどん小さくなる
      int b = a - c; // どんどん小さくなる
      if (a <= 0 || b <= 0) break; // x, c, 調和級数 計算量

      int k1 = x * c; // どんどん大きくなる
      int k2 = a;

      if (k1 == k2 || k1 >= n || k2 < 0) break;
      if (st.count(k1) || st.count(k2)) break;
      st.insert(k1);
      st.insert(k2);

      tmp += s[k1];
      tmp += s[k2];
      chmax(ans, tmp);
    }
  }
  cout << ans << endl;
}
