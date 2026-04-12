// 2020-06-26 20:34:13
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using ull = unsigned long long;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

const int MAX_N = 500;
int n;
vector<int> s[2], w[2];
vector<ull> u[2];
vector<vector<int>> g;

void flip() {
  rep(i, n) rep(j, i) swap(g[i][j], g[j][i]);
}
bool solve() {
  g.assign(n, vector<int>(n, -1));
  rep(k, 2) {
    rep(i, n) {
      int x = w[k][i];
      if(s[k][i] != x) {
        rep(j, n) {
          if(g[i][j] == -1) g[i][j] = x;
          else if(g[i][j] != x) return false;
        }
      }
    }
    flip();
  }
  rep(_, 2) {
    rep(k, 2) {
      rep(i, n) {
        int x = w[k][i];
        if(s[k][i] == x) {
          bool ok = false;
          vector<int> idx;
          rep(j, n) {
            if(g[i][j] == x) ok = true;
            else if(g[i][j] == -1) idx.emplace_back(j);
          }
          if(!ok) {
            if(idx.size() == 0) return false;
            else if(idx.size() == 1) g[i][idx[0]] = x;
          }
        }
      }
      flip();
    }
  }
  vector<int> is, js;
  rep(k, 2) {
    rep(i, n) {
      rep(j, n) {
        if(g[i][j] == -1) {
          if(k == 0) is.push_back(i);
          else js.push_back(i);
          break;
        }
      }
    }
    flip();
  }
  rep(i, is.size()) rep(j, js.size()) {
    g[is[i]][js[j]] = (i+j) % 2;
  }
  return true;
}
void answer() {
  cin >> n;
  rep(i, 2) {
    s[i].resize(n);
    rep(j, n) cin >> s[i][j];
  }
  rep(i, 2) {
    u[i].resize(n);
    w[i].resize(n);
    rep(j, n) cin >> u[i][j];
  }
  vector<vector<ull> > ans(n, vector<ull>(n, 0));
  rep(d, 64) {
    rep(i, 2) {
      rep(j, n) w[i][j] = (u[i][j] >> d) & 1;
    }
    if(solve()) {
      rep(i, n) rep(j, n) ans[i][j] |= (ull(g[i][j]) << d);
    } else {
      cout << -1 << "\n";
      return;
    }
  }
  rep(i, n) {
    rep(j, n) {
      if(j) cout << " ";
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}