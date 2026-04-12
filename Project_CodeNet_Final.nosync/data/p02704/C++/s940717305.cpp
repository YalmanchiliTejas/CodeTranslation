// 2020-08-11 22:41:57
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

using ull = unsigned long long;
int n;
vector<vector<int> > A;
vector<int> ST[2];
vector<int> UV[64][2];
void transpose() {
  rep(i, n) REP(j, i+1, n) swap(A[i][j], A[j][i]);
}
bool solve(int b) {
  A.assign(n, vector<int>(n, -1));
  rep(k, 2) {
    rep(i, n) {
      if(ST[k][i] == 0 && UV[b][k][i] == 1) {
        rep(j, n) {
          if(A[i][j] == 0) return false;
          A[i][j] = 1;
        }
      } else if(ST[k][i] == 1 && UV[b][k][i] == 0) {
        rep(j, n) {
          if(A[i][j] == 1) return false;
          A[i][j] = 0;
        }
      }
    }
    transpose();
  }
  rep(_, 2) {
    rep(k, 2) {
      rep(i, n) {
        if(ST[k][i] != UV[b][k][i]) continue;
        bool ok = false;
        vector<int> idx;
        int x = ST[k][i];
        rep(j, n) {
          if(A[i][j] == x) {
            ok = true;
          } else if(A[i][j] == -1) {
            idx.push_back(j);
          }
        }
        if(ok) continue;
        if(idx.size() == 0) return false;
        if(idx.size() == 1) A[i][idx[0]] = x;
      }
      transpose();
    }
  }
  vector<int> is, js;
  rep(k, 2) {
    rep(i, n) rep(j, n) {
      if(A[i][j] == -1) {
        if(k == 0) is.push_back(i);
        else js.push_back(i);
        break;
      }
    }
    transpose();
  }
  rep(i, is.size()) rep(j, js.size()) {
    A[is[i]][js[j]] = (i + j) % 2;
  }
  return true;
}
void answer() {
  cin >> n;
  rep(k, 2) rep(i, n) {
    int x;
    cin >> x;
    ST[k].push_back(x);
  }
  rep(k, 2) rep(i, n) {
    ull x;
    cin >> x;
    rep(j, 64) UV[j][k].push_back((x>>j)&1);
  }
  vector<vector<ull> > ans(n, vector<ull>(n, 0));
  rep(b, 64) {
    if(solve(b)) {
      rep(i, n) {
        rep(j, n) {
          ans[i][j] |= (ull(A[i][j])<<b);
        }
      }
    } else {
      cout << -1 << '\n';
      return;
    }
  }
  rep(i, n) {
    rep(j, n) {
      if(j) cout << ' ';
      cout << ans[i][j];
    }
    cout << '\n';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}