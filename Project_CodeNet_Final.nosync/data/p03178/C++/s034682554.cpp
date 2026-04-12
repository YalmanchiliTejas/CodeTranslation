#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int dp[12345][123];
//main
signed main(){
  string s;int D;cin>>s>>D;
  int sum=0;
  memset(dp,0,sizeof(dp));
  for(int i=0;i<s.size();i++){
    for(int j=0;j<D;j++){
      for(int k=0;k<10;k++){dp[i+1][(j+k)%D]+=dp[i][j];dp[i+1][(j+k)%D]%=MOD;}
    }
    for(int k=0;k<s[i]-'0';k++){dp[i+1][(sum+k)%D]++;dp[i+1][(sum+k)%D]%=MOD;}
    sum+=s[i]-'0';
    sum%=MOD;
  }
  int a=0;
  for(char p:s)a+=p-'0';a%=D;
  if(a==0)cout<<dp[s.size()][0]<<endl;
  else cout<<(dp[s.size()][0]-1+MOD)%MOD<<endl;
}
