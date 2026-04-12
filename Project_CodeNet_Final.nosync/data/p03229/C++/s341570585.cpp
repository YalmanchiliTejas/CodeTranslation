#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

namespace solver {
  using namespace std;
  typedef long long ll;

  int N;
  vector<int> vec;

  void init() {
    cin >> N;
    int a;
    rep(i, N) {
      cin >> a;
      vec.push_back(a);
    }
  }

  ll calc(int l, int r, int li, int ri) {
    ll res = 0;
    while(li <= ri) {
      int l_l = abs(l - vec[li]);
      int l_r = abs(l - vec[ri]);
      int r_l = abs(r - vec[li]);
      int r_r = abs(r - vec[ri]);
      int maxv = max({l_l, l_r, r_l, r_r});
      res += maxv;
      if(maxv == l_l) {
        l = vec[li];
        li++;
      } else if(maxv == l_r) {
        l = vec[ri];
        ri--;
      } else if(maxv == r_l) {
        r = vec[li];
        li++;
      } else {
        r = vec[ri];
        ri--;
      }
    }
    return res;
  }

  void solve() {
    sort(vec.begin(), vec.end());
    ll ans = 0;
    ans = max(ans, calc(vec.front(), vec.front(), 1, vec.size()-1));
    ans = max(ans, calc(vec.back(), vec.back(), 0, vec.size()-2));
    cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}