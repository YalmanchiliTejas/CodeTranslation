#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)

template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }

typedef long long ll;
const int MAXSIZE = 3000 + 10;
ll dp[MAXSIZE][MAXSIZE][2];
vector<ll> a;
const ll LINF = 1LL<<60;

ll dfs(int left, int right, int turn) {
  ll ans = 0, tmp;
  if(dp[left][right][turn] > -LINF) {
    return dp[left][right][turn];
  }
  if(left < right) {
    if(turn == 0) {
      ans = -LINF;
      tmp = dfs(left + 1, right, 1 - turn);
      chmax(ans, tmp + a[left]);
      tmp = dfs(left, right - 1, 1 - turn);
      chmax(ans, tmp + a[right-1]);
    } else {
      ans = LINF;
      tmp = dfs(left + 1, right, 1 - turn);
      chmin(ans, tmp - a[left]);
      tmp = dfs(left, right - 1, 1 - turn);
      chmin(ans, tmp - a[right-1]);
    }
  }
  //  cout << left << " " << right << " " << turn << "=" << ans << endl;
  return dp[left][right][turn] = ans;
}

int main() {
  int N; cin>>N;
  a = vector<ll>(N);
  REP(i,N) cin>>a[i];

  REP(i,MAXSIZE) REP(j,MAXSIZE) REP(k, 2) {
    dp[i][j][k] = -LINF;
  }
  ll ans = dfs(0, N, 0);
  cout << ans << endl;
  return 0;
}
