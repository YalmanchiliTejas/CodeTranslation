#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll INF = 1e15;

int N;
vector<ll> v;
ll dp[2][3005][3005];

ll solve(int p, int i, int j){
  if(dp[p][i][j] != -INF) return dp[p][i][j];
  if(i==j) return dp[p][i][j] = ((p==0)?1:-1) * v[i];
  if(p == 0){
    if(solve(1-p,i+1,j) + v[i] < solve(1-p,i,j-1) + v[j]){
      return dp[p][i][j] = solve(1-p,i,j-1) + v[j];
    }else{
      return dp[p][i][j] = solve(1-p,i+1,j) + v[i];
    }
  }else{
    if(solve(1-p,i+1,j) - v[i] < solve(1-p,i,j-1) - v[j]){
      return dp[p][i][j] = solve(1-p,i+1,j) - v[i];
    }else{
      return dp[p][i][j] = solve(1-p,i,j-1) - v[j];
    }    
  }
}

int main(){
  cin >> N;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  rep(p,2) rep(i,3005) rep(j,3005) dp[p][i][j] = -INF;
  
  cout << solve(0, 0, N-1) << endl;
  
  return 0;
}
