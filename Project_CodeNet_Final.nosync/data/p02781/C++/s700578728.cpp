#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;
struct edge {
    int to, cost;
};

int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

map<int,int> factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////

signed main() {
string s;
cin>>s;
int n;
n=s.size();
int k;
cin>>k;

int dp[100][4][2];
rep(i,100)rep(j,4)rep(k,2)dp[i][j][k]=0;
dp[0][1][1]=s[0]-'0'-1;
dp[0][0][1]=1;
dp[0][1][0]=1;
rep(i,n-1){
  if(s[i+1]!='0'){
    dp[i+1][0][1]=dp[i][0][1];
    for(int j=1;j<4;j++){
      dp[i+1][j][1]=dp[i][j][1]+dp[i][j-1][1]*9+dp[i][j][0]+dp[i][j-1][0]*(s[i+1]-'0'-1);
      dp[i+1][j][0]=dp[i][j-1][0];
  }
}
else {
  dp[i+1][0][1]=dp[i][0][1];
  for(int j=1;j<4;j++){
    dp[i+1][j][1]=dp[i][j][1]+dp[i][j-1][1]*9+dp[i][j-1][0]*(s[i+1]-'0');
    dp[i+1][j][0]=dp[i][j][0];
}
}

}
cout<<dp[n-1][k][0]+dp[n-1][k][1]<<endl;
}
