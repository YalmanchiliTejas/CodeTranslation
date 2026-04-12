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
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
#define debug(output) cout<<#output<<"= "<<output<<endl
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  int d;cin>>d;
  vector<lint> dp(d+1,0);
  int rest=0;
  int n=s.length();
  rep(i,n){
      vector<lint> buf(d+1,0);
      int top=s[i]-'0';
      rep(j,10){
          rep(k,d){
              buf[(k+j)%d]+=dp[k];
              buf[(k+j)%d]%=MOD;
          }
      }
      rep(j,top){
          buf[(rest+j)%d]+=1;
          buf[(rest+j)%d]%=MOD;
      }
      rest+=top;rest%=d;
      swap(buf,dp);
  }
  if(rest==0)++dp[0];
  dp[0]+=MOD-1;
  dp[0]%=MOD;
  cout<<dp[0]<<"\n";
  return 0;
}