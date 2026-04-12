#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=100000000000000007;
const int MOD=998244353;
signed main(){
  int n,s;cin>>n>>s;
  vector<vector<vector<int>>> dp(3,vector<vector<int>>(3005,vector<int>(3005,0)));
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  dp[1][0][a[0]]=1;
  dp[1][0][0]=1;
  rep1(i,n-1){
    dp[1][i-1][0]++;
    rep(j,3005){
      dp[1][i][j]=dp[1][i-1][j];
      dp[2][i][j]=dp[2][i-1][j];
      if(j>=a[i]){
        dp[1][i][j]+=dp[1][i-1][j-a[i]];
        dp[1][i][j]%=MOD;
        dp[2][i][j]+=dp[1][i-1][j-a[i]]*(n-i);
        dp[2][i][j]%=MOD;
      }
    }
  }
  cout<<dp[2][n-1][s]<<"\n";
  return 0;
}
