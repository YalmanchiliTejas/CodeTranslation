#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vi s(n), t(n);
  vector<ull> u(n), v(n);

  rep(i,0,n) cin >> s[i];
  rep(i,0,n) cin >> t[i];

  rep(i,0,n) cin >> u[i];
  rep(i,0,n) cin >> v[i];

  auto solve = [&](vi &rt, vi &ct, vi &rows, vi &cols) -> vvi {
    vvi ans(n, vi(n));
    vi ch(n, n-1);
    rep(i,0,n) {
      if (rt[i] ^ rows[i]) ch[i] = 0;
      if (rows[i]) rep(j,0,n) ans[i][j] = 1;
    }

    rep(j,0,n) {
      if (ct[j] ^ cols[j]) {
        rep(i,0,n) if (ch[i]) {
          if (ans[i][j] != cols[j]) --ch[i];
          ans[i][j] = cols[j];
        }
      } else {
        int mi = 0;
        rep(i,0,n) {
          if (ans[i][j] == cols[j]) {
            mi=-1;
            break;
          }
          if (ch[i] > ch[mi]) {
            mi = i;
          }
        }
        if (mi >= 0 and ch[mi]) {
          ans[mi][j] = cols[j];
          --ch[mi];
        }
      }
    }

    return ans;
  };

  vector<vector<ull>> ans(n, vector<ull>(n));

  rep(i,0,64) {
    vi rt(n), ct(n);
    vi rows(n), cols(n);
    rep(j,0,n) {
      if ((u[j]>>i)&1) rows[j] = 1;
      if ((v[j]>>i)&1) cols[j] = 1;
      rt[j] = s[j];
      ct[j] = t[j];
    }

    vvi bit = solve(rt, ct, rows, cols);
    rep(j,0,n) rep(k,0,n) ans[j][k] |= ull(bit[j][k])<<i;
  }

  bool suc= true;
  rep(i,0,n) {
    ull val = 0;
    if (!s[i]) {
      val = ans[i][0];
      rep(j,0,n) val &= ans[i][j];
      suc &= val == u[i];
    } else {
      rep(j,0,n) val |= ans[i][j];
      suc &= val == u[i];
    }
  }

  rep(j,0,n) {
    ull val = 0;
    if (!t[j]) {
      val = ans[0][j];
      rep(i,0,n) val &= ans[i][j];
      suc &= val == v[j];
    } else {
      rep(i,0,n) val |= ans[i][j];
      suc &= val == v[j];
    }
  }

  if (suc) {
    rep(i,0,n) {
      rep(j,0,n) cout << ans[i][j] << ' ';
      cout << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
}