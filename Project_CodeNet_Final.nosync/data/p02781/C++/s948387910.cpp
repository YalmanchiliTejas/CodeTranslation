#include<bits/stdc++.h>
using namespace std;
#define int long
signed main(){
  string n;
  int p,a;
  cin>>n>>p;
  a=n.size();
  int dp[103][10][2][4]={0};
  const int low=0,eq=1;
  dp[0][0][low][0]=1;
  for(int i=1;i<n[0]-'0';++i)dp[0][i][low][1]=1;
  dp[0][n[0]-'0'][eq][1]=1;
  for(int i=1;i<a;++i){
    int digit=n[i]-'0',prev=n[i-1]-'0';
    for(int j=0;j+(digit!=0)<=p;++j){
      dp[i][digit][eq][j+(digit!=0)]=dp[i-1][prev][eq][j];
    }
    for(int x=0;x<10;++x)for(int y=0;y+(x!=0)<=p;++y)for(int z=0;z<10;++z)
      dp[i][x][low][y+(x!=0)]+=dp[i-1][z][low][y]+(x<digit?dp[i-1][z][eq][y]:0);
  }
  int res=0;
  for(int i=0;i<10;++i)for(int j=0;j<=1;++j)res+=dp[a-1][i][j][p];
  cout<<res;
}