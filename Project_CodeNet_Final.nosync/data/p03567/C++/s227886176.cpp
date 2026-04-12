#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//typedef long long ll;

#define INF (1LL << 31 - 1)
#define INFLL ((1LL << 62) - 1)
#define MOD int(1e9+7)
#define repi(i,j,n) for(int i = (j); i < (n); ++i)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) for (int i = n; i >= 0; --i)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

int vx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, vy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

inline bool check(int ux, int uy, int x, int y) {
  return (0 <= x and x < ux and 0 <= y and y < uy);
}

inline void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
  string s;

  cin >> s;
  for (int i = 1; i < s.size(); ++i) {
    if (s.substr(i-1, 2) == "AC") {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  
  return 0;
}
