#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  string n;int k;cin>>n>>k;
  int dig=n.size();
  int i,j;
  vector<int> num(dig);
  rep(i,dig)num[i]=n[i]-'0';
  vector<vector<int>> dp0(dig+1,vector<int>(k+1,0));
  vector<vector<int>> dp1(dig+1,vector<int>(k+1,0));
  dp1[0][0]=1;
  for(i=1;i<=dig;i++)
  {
    for(j=0;j<=k;j++)
    {
      if(num[i-1]==0)
      {
        dp0[i][j]+=dp0[i-1][j];
        if(j-1>=0)dp0[i][j]+=dp0[i-1][j-1]*9;
        dp1[i][j]+=dp1[i-1][j];
      }
      else
      {
        dp0[i][j]+=dp0[i-1][j]+dp1[i-1][j];
        if(j-1>=0)
        {
          dp0[i][j]+=dp0[i-1][j-1]*9;
          dp0[i][j]+=dp1[i-1][j-1]*(num[i-1]-1);
          dp1[i][j]+=dp1[i-1][j-1];
        }
      }
    }
  }
  cout<<dp0[dig][k]+dp1[dig][k]<<endl;
}
