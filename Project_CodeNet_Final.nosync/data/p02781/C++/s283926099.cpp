#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  string s;
  int k;
  cin>>s>>k;
  int n=s.size();
  vector<vector<ll>>dp0(101,vector<ll>(4));
  vector<vector<ll>>dp1(101,vector<ll>(4));
  dp0[0][0]=1;
  dp0[0][1]=max(0,(s[0]-'0')-1);
  dp0[0][2]=0;
  dp0[0][3]=0;
  dp1[0][0]=0;
  dp1[0][1]=1;
  dp1[0][2]=0;
  dp1[0][3]=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<=k;j++){
      if(j-1>=0) dp0[i][j]=dp0[i-1][j]+9*dp0[i-1][j-1];
      else dp0[i][j]=dp0[i-1][j];
      if(s[i]!='0') dp0[i][j]+=dp1[i-1][j];
      if(j-1>=0) dp0[i][j]+=(max((s[i]-'0')-1,0))*dp1[i-1][j-1];
      if(s[i]=='0') dp1[i][j]+=dp1[i-1][j];
      if(j-1>=0 && s[i]!='0') dp1[i][j]+=dp1[i-1][j-1];
    }
  }
  cout<<dp0[n-1][k]+dp1[n-1][k]<<endl;
}