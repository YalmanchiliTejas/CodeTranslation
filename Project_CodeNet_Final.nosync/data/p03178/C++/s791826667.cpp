#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); }
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
#define forxr(i,n) for(int i = (n)-1; i >= 0; --i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second
#define all(c) c.begin(),c.end()

template <int MOD>
struct modint {
  int v; modint(int val=0) : v(val) { if ((v%= MOD) < 0) v += MOD; }
  modint& operator += (const modint& b) { (v += b.v) %= MOD; return *this; }
  modint& operator -= (const modint& b) { return (*this) += MOD-b.v; }
  modint& operator *= (const modint& b) { v = ((ll)v*(ll)b.v) % MOD; return *this; }
  modint& operator /= (const modint& b) { return (*this) *= b.pow(MOD-2); }
#define _op(op, op2) modint operator op (const modint& b) const { modint ans = *this; return ans op2 b; }
  _op(+, +=); _op(-, -=); _op(*, *=); _op(/, /=);
#undef _op
  modint pow(ll e) const { modint res(1), b(*this); for (; e>0; e/=2, b*=b) { if (e&1) res*=b; } return res; }
};

using mi = modint<(int)1e9+7>;

const int N = 1e5+5, D = 102;
string k;
int d;
mi dp[N][D][2];
bool vis[N][D][2];

mi solve(int i, int m, bool tight) {
  if (i == k.size()) {
    return m == 0;
  }
  if (!vis[i][m][tight]) {
    if (tight) {
      int maxd = k[i] - '0';
      dp[i][m][1] += solve(i+1, (m+maxd)%d, 1);
      for (int j = 0; j < maxd; ++j) {
        dp[i][m][1] += solve(i+1, (m+j)%d, 0);
      }
    } else {
      for (int j = 0; j < 10; ++j) {
        dp[i][m][0] += solve(i+1, (m+j)%d, 0);
      }
    }
    vis[i][m][tight] = 1;
  }
  return dp[i][m][tight];
}

int main() { // Emily <3
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> k >> d;
  mi ans = solve(0, 0, 1) - 1;
  cout << ans.v << nl;

  return 0;
}

