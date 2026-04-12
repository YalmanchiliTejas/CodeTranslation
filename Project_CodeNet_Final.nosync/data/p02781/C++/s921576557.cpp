#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include <cmath>


using namespace std;

char N[101],len;

int K,i,j,k,memo[101][2][4],num;

int dp(int n,int m,int u)
{
  if(memo[n][m][u]!=-1)
  {
    return memo[n][m][u];
  }
  
  int s,t;
  
  if(m==1)
  {
    if(N[n]-'0'==0)
    {
      s=dp(n-1,m,u);
      memo[n][m][u]=s;
      return s;
    }
    else if(u>0)
    {
      s=dp(n-1,m,u-1);
      memo[n][m][u]=s;
      return s;
    }
  }
  
  if(m==0)
  {
    s=dp(n-1,m,u);
    if(u>0)
    {
      s+=dp(n-1,m,u-1)*9;
    }
    
    if(N[n]-'0'>0)
    {
      s+=dp(n-1,1,u);
      if(u>0)
      {
        s+=dp(n-1,1,u-1)*(N[n]-'0'-1);
      }
    }   
    
    memo[n][m][u]=s;
    
    return s;
    
  }
  
  
  
  
}


int main()
{

  cin >>N>>K;
  
  len=strlen(N);
  
  for(i=0;i<len;i++)
  {
    for(k=0;k<4;k++)
    {
      memo[i][0][k]=-1;
      memo[i][1][k]=-1;
    }
    memo[i][0][0]=1;
    memo[i][1][0]=0;

  }
  
  memo[0][0][0]=1;
  memo[0][0][1]=N[0]-'0'-1;
  memo[0][1][1]=1;
  
  memo[0][1][0]=0;
  
  for(i=2;i<4;i++)
  {
    memo[0][0][i]=0;
    memo[0][1][i]=0;
  }
  
  cout << dp(len-1,0,K)+dp(len-1,1,K);
  
  
  
}



