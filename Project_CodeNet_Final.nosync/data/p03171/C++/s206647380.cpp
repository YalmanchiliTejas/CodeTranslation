#include <iostream>

using namespace std;
using ll = long long;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<"\n"
const ll INF = 1e14;

ll dp[3001][3001];
int A[3001];
ll solve(int s, int t) {
  if (s == t)
    return 0;
  if (dp[s][t] != INF)
    return dp[s][t];
  return dp[s][t] = max((ll)A[t-1] - solve(s, t-1), (ll)A[s] - solve(s+1, t));
}
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  IN(N);

  REP(i, 3001) REP(j, 3001)
    dp[i][j] = INF;

  REP(i, N)
    cin >> A[i];
  OUT(solve(0, N));

  return 0;
}
