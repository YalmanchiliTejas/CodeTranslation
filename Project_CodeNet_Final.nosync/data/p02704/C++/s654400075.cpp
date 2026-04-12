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
vector<vector<int> > A[64];
vector<int> ST[2];
vector<int> UV[64][2];
void transpose(int b) {
  rep(i, n) REP(j, i+1, n) swap(A[b][i][j], A[b][j][i]);
}
bool solve(int b) {
  A[b].assign(n, vector<int>(n, -1));
  rep(k, 2) {
    rep(i, n) {
      if(ST[k][i] == 0 && UV[b][k][i] == 1) {
        rep(j, n) {
          if(A[b][i][j] == 0) return false;
          A[b][i][j] = 1;
        }
      } else if(ST[k][i] == 1 && UV[b][k][i] == 0) {
        rep(j, n) {
          if(A[b][i][j] == 1) return false;
          A[b][i][j] = 0;
        }
      }
    }
    transpose(b);
  }
  rep(_, 2) {
    rep(k, 2) {
      rep(i, n) {
        if(ST[k][i] != UV[b][k][i]) continue;
        bool ok = false;
        vector<int> idx;
        int x = ST[k][i];
        rep(j, n) {
          if(A[b][i][j] == x) {
            ok = true;
          } else if(A[b][i][j] == -1) {
            idx.push_back(j);
          }
        }
        if(ok) continue;
        if(idx.size() == 0) return false;
        if(idx.size() == 1) A[b][i][idx[0]] = x;
      }
      transpose(b);
    }
  }
  set<int> is, js;
  rep(i, n) rep(j, n) if(A[b][i][j] == -1) {
    is.insert(i);
    js.insert(j);
  }
  int base = 1;
  for(int i : is) {
    base = 1 - base;
    int c = base;
    for(int j : js) {
      A[b][i][j] = c;
      c = 1 - c;
    }
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
  rep(b, 64) if(!solve(b)) {
    cout << -1 << '\n';
    return;
  }
  rep(i, n) {
    rep(j, n) {
      ull x = 0;
      rep(b, 64) x |= (ull(A[b][i][j])<<b);
      if(j) cout << ' ';
      cout << x;
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