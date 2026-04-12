#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int K;
  cin>>s>>K;
  int N=s.size();
  vector<int>n(N);
  for(int i=0;i<N;i++)n[i]=s[i]-'0';

  vector<vector<vector<ll>>>dp(N+1,vector<vector<ll>>(2,vector<ll>(K+2,0)));
  dp[0][0][0]=1;

  for(int i=0;i<N;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<=(j?9:n[i]);k++){
        for(int l=0;l<=K;l++){
          if(k!=0)dp[i+1][j|k<n[i]][l+1]+=dp[i][j][l];
          else dp[i+1][j|k<n[i]][l]+=dp[i][j][l];
        }
      }
    }
  }

  cout<<dp[N][0][K]+dp[N][1][K]<<endl;

  return 0;
}
