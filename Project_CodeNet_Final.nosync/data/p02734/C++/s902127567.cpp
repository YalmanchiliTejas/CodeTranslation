#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include <cmath>

using namespace std;

long long N,i,j,k,memo[3002][3002],all,ans,M,S,A[3002],MOD;

int dp(int n,int m)
{
  if(memo[n][m]!=-1)
  {
    return memo[n][m];
  }
  
  int u,v;
  
  u=dp(n-1,m);
  u%=MOD;
  if(m>A[n])
  {
    u+=dp(n-1,m-A[n]);
  }
  else if(m==A[n])
  {
    u+=dp(n-1,0)+1;
  }
  u%=MOD;
  memo[n][m]=u;
  return u;
  
}

int main()
{
  MOD=998244353;
  
  cin>> N>>S;
  
  for(i=0;i<N;i++)
  {
    cin>>A[i];
  }
  
  for(i=0;i<N;i++)
  {
    for(j=0;j<S+1;j++)
    {
      memo[i][j]=-1;
    }
  }
  
  for(i=0;i<N;i++)
  {
    memo[i][0]=i+1;
  }
  for(j=1;j<S+1;j++)
  {
    memo[0][j]=0;
  }
  memo[0][A[0]]=1;
  
  ans=0;
  
  for(i=0;i<N;i++)
  {
    ans+=dp(i,S);
    ans%=MOD;
  }

  cout <<ans;
  

  
}