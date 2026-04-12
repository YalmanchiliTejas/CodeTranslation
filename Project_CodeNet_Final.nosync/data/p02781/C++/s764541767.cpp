#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  int k;
  cin>>s>>k;
  int n=s.size();
  int dp0[n+1][k+1];
  int dp1[n+1][k+1];
  rep(i,0,k+1) dp0[0][i]=0;
  rep(i,1,n+1) dp0[i][0]=1;
  rep(i,1,k+1) dp1[0][i]=0;
  rep(i,1,n+1) dp1[i][0]=0;
  dp1[0][0]=1;
  rep(i,0,n){
    rep(j,0,k){
      if(s.at(i)=='0'){
        dp0[i+1][j+1]=dp0[i][j+1]+dp0[i][j]*9;
        dp1[i+1][j+1]=dp1[i][j+1];
      }
      else{
        dp0[i+1][j+1]=dp0[i][j+1]+dp1[i][j+1]+dp0[i][j]*9+dp1[i][j]*(s.at(i)-'0'-1);
        dp1[i+1][j+1]=dp1[i][j];
      }
    }
  }
  cout<<dp0[n][k]+dp1[n][k]<<endl;
}
