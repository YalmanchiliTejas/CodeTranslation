#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vl A(N);
  rep(i,N) cin >> A[i];
  ll ans;
  
  if(N%2) {
    vvl dp(N/2+1,vl(3));
    rep(i,N/2) {
      dp[i+1][0]=dp[i][0]+A[2*i];
      dp[i+1][1]=max(dp[i][0],dp[i][1])+A[2*i+1];
      dp[i+1][2]=max(dp[i+1][1]-A[2*i+1],dp[i][2])+A[2*i+2];
    }
    ans=max(max(dp[N/2][0],dp[N/2][1]),dp[N/2][2]);
  }
  else {
    vvl dp(N/2+1,vl(2));
    rep(i,N/2) {
      dp[i+1][0]=dp[i][0]+A[2*i];
      dp[i+1][1]=max(dp[i][0],dp[i][1])+A[2*i+1];
    }
    ans=max(dp[N/2][0],dp[N/2][1]);
  }
  
  cout << ans << endl;
}