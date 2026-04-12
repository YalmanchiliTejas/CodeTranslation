#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

bool check(
    const vector<uint64_t>& s,
    const vector<uint64_t>& t,
    const vector<uint64_t>& u,
    const vector<uint64_t>& v,
    const vector<vector<uint64_t>>& mat) {
  int n = size(mat);
  REP(i,n) {
    if (s[i] == 0) { // AND
      uint64_t bits = ~UINT64_C(0);
      REP(j,n) {
        bits &= mat[i][j];
      }
      if (bits != u[i]) return false;
    } else { // OR
      uint64_t bits = 0;
      REP(j,n) {
        bits |= mat[i][j];
      }
      if (bits != u[i]) return false;
    }
    if (t[i] == 0) { // AND
      uint64_t bits = ~UINT64_C(0);
      REP(j,n) {
        bits &= mat[j][i];
      }
      if (bits != v[i]) return false;
    } else { // OR
      uint64_t bits = 0;
      REP(j,n) {
        bits |= mat[j][i];
      }
      if (bits != v[i]) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  vector<uint64_t> s(n), t(n), u(n), v(n);
  for(auto&& e:s)cin>>e;
  for(auto&& e:t)cin>>e;
  for(auto&& e:u)cin>>e;
  for(auto&& e:v)cin>>e;
  vector<vector<uint64_t>> mat(n, vector<uint64_t>(n, 0));
  REP(i,64) {
    vector<vecint> tmp(n, vecint(n, -1));
    vector<bool> fixedv(n, false), fixedh(n, false);
    REP(j,n) {
      if (((u[j]>>i)&1) != s[j]) { // ALL
        int need = 1 - s[j];
        REP(k,n) {
          tmp[j][k] = need;
        }
        fixedh[j] = true;
      }
      if (((v[j]>>i)&1) != t[j]) { // ALL
        int need = 1 - t[j];
        REP(k,n) {
          tmp[k][j] = need;
        }
        fixedv[j] = true;
      }
    }
    REP(j,n) {
      if (((u[j]>>i)&1) == s[j]) { // EXIST s[j]
        int need = s[j];
        bool sat = false;
        int unknown = 0;
        REP(k,n) {
          if (tmp[j][k] == need) sat = true;
          if (tmp[j][k] == -1) ++unknown;
        }
        if (!sat && unknown == 1) {
          REP(k,n) {
            if (tmp[j][k] == -1) tmp[j][k] = need;
          }
          unknown = 0;
        }
        if (unknown == 0) fixedh[j] = true;
      }
    }
    REP(j,n) {
      if (((v[j]>>i)&1) == t[j]) { // EXIST t[j]
        int need = t[j];
        bool sat = false;
        int unknown = 0;
        REP(k,n) {
          if (tmp[k][j] == need) sat = true;
          if (tmp[k][j] == -1) ++unknown;
        }
        if (!sat && unknown == 1) {
          REP(k,n) {
            if (tmp[k][j] == -1) tmp[k][j] = need;
          }
          unknown = 0;
        }
        if (unknown == 0) fixedv[j] = true;
      }
    }
    REP(j,n) {
      if (((u[j]>>i)&1) == s[j]) { // EXIST s[j]
        int need = s[j];
        bool sat = false;
        int unknown = 0;
        REP(k,n) {
          if (tmp[j][k] == need) sat = true;
          if (tmp[j][k] == -1) ++unknown;
        }
        if (!sat && unknown == 1) {
          REP(k,n) {
            if (tmp[j][k] == -1) tmp[j][k] = need;
          }
          unknown = 0;
        }
        if (unknown == 0) fixedh[j] = true;
      }
    }
    int cr = 0;
    REP(j,n) {
      int cc = 0;
      REP(k,n) {
        if (!fixedh[j] && !fixedv[k]) {
          tmp[j][k] = (cc+cr) % 2;
        }
        if (!fixedv[k]) ++cc;
      }
      if (!fixedh[j]) ++cr;
    }
    REP(j,n)REP(k,n) {
      if (tmp[j][k] == -1) {
        cout<<-1<<"\n";
        return 0;
      }
      mat[j][k] |= static_cast<uint64_t>(tmp[j][k]) << i;
    }
  }
  if (check(s, t, u, v, mat)) {
    REP(i,n) {
      REP(j,n) {
        if(j) cout << " ";
        cout << mat[i][j];
      }
      cout << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
  return 0;
}
