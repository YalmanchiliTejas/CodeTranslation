#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int add(int&x,int y){return(x+=y)<MOD?x:x-=MOD;}

char num[10005];
int dp[10005][105][2];

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int D;
  cin>>num+1>>D;
  dp[0][0][0]=1;
  int n=strlen(num+1);
  reverse(num+1,num+n+1);
  for(int i=1;i<=n;++i){
    for(int j=0;j<D;++j){
      for(int k=0;k<10;++k){
        add(dp[i][(j+k)%D][0],dp[i-1][j][0]);
        if(k<num[i]-'0'){
          add(dp[i][(j+k)%D][1],dp[i-1][j][0]);
        }
      }
    }
  }
  int sum=0;
  int sol=MOD-1;
  for(int i=n;i;--i){
    add(sol,dp[i][(D-sum)%D][1]);
    sum=(sum+num[i]-'0')%D;
  }
  cout<<sol+!(sum%D)<<'\n';
}
