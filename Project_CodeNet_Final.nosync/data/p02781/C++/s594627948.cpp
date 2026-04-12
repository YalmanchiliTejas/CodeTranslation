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

  string N;
  int K;
  cin>>N>>K;
  int n=N.size();
  vector<int>num(n);
  for(int i=0;i<n;i++){
    num[i]=(N[i]-'0');
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    //dp[上からの桁数][フラグ][0の個数]
    vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(2,vector<ll>(K+2,0)));
    if(i==0)dp[i][0][0]=1;
    else dp[i][1][0]=1;
    for(int j=i;j<n;j++){
      for(int k=0;k<2;k++){
        for(int l=(j==i?1:0);l<=(k?9:num[j]);l++){
          for(int m=0;m<K+2;m++){
            if(l!=0)dp[j+1][k||(l<num[j])][min(m+1,K+1)]+=dp[j][k][m];
            else dp[j+1][k||(l<num[j])][m]+=dp[j][k][m];
          }
        }
      }
    }
    ans+=dp[n][0][K]+dp[n][1][K];
  }
  cout<<ans<<endl;
  return 0;
}
