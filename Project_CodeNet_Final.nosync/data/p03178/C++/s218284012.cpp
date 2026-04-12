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
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  int d;cin>>d;
  int n=s.size();
  vector<vector<int>> dp(d,vector<int>(n+1,0));
  int sup=0;
  rep1(i,n){
      rep(j,d){
          rep(k,10){
              dp[(j+k)%d][i]+=dp[j][i-1];
              dp[(j+k)%d][i]%=MOD;
          }
      }
      int num=s[i-1]-'0';
      for(int j=0;j<num;++j){
          dp[(sup+j)%d][i]+=1;
          dp[(sup+j)%d][i]%=MOD;
      }
      sup+=num;
      sup%=d;
  }
  if(sup==0){
      dp[0][n]+=1;
      dp[0][n]%=MOD;
  }
  rep(j,0){
      printf("j = %lld, ",j);
      rep1(i,n){
          cout<<dp[j][i]<<" ";
      }
      cout<<endl;
  }
  cout<<(dp[0][n]+MOD-1)%MOD<<"\n";
  return 0;
}