#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))

int N;
vector<int> A;

// dp[l][r] := [l,r]に操作を行う際のmax,min
// (N - r + l) % 2 == 1 なら太郎なのでmax
// (N - r + l) % 2 == 0 なら次郎なのでmin
ll dp[3030][3030];
bool defined[3030][3030];

bool isTaro(int l, int r) {
  return (N - r + l) % 2 == 1;
}

ll rec(int l, int r) {
  if (defined[l][r]) return dp[l][r];
  if (l == r) return (N % 2 ? 1 : -1) * A[l];
  defined[l][r] = true;
  if (isTaro(l, r)) {
    // 左から
    ll t_l = A[l] + rec(l + 1, r);
    // 右から
    ll t_r = A[r] + rec(l, r - 1);
    return dp[l][r] = max<ll>(t_l, t_r);
  } else {
    // 左から
    ll t_l = -A[l] + rec(l + 1, r);
    // 右から
    ll t_r = -A[r] + rec(l, r - 1);
    return dp[l][r] = min<ll>(t_l, t_r);
  }
}

signed main() {

  cin >> N;
  A.resize(N);
  REP(i, N) cin >> A[i];

  cout << rec(0, N - 1) << endl;

}
