//inspiration: https://www.hackerrank.com/topics/digit-dp
#include <iostream>
#include <cstdio>
#include <cstring>
 using namespace std;

#define int long long 
const int mod=1e9+7;
string s;
int dp[10005][2][105],n,d;

int solve(int idx,bool smaller,int rem)
{
  if(idx==n)
  {
    return (rem!=0)?0:1;
  }
  if(dp[idx][smaller][rem]!=-1)
    return dp[idx][smaller][rem];

  int limit=9;
  if(smaller)
    limit=s[idx]-'0';

  int cnt=0;
  
  for(int i=0;i<=limit;i++)
  {
    bool smflag;
    if(i<(s[idx]-'0'))
      smflag=0;
    else
      smflag=smaller;

    cnt=(cnt % mod + solve(idx+1,smflag,(rem+i) % d) % mod) % mod;
  }

  return dp[idx][smaller][rem]=cnt;
}

int32_t main()
{
  cin>>s>>d;
  n=s.size();
  if(d>9*n)
  {
    cout<<0; exit(0);
  }

  memset(dp,-1,sizeof(dp));

  int ans=solve(0,1,0);

  cout<<(ans+mod-1)%mod;
  
 
  return 0;  
}   