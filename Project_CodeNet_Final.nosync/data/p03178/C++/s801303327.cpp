#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
typedef unsigned long long ull;
typedef signed long long sll;
using namespace std;

#define INF 0x7FFFFFFFFFFFFFFF
#define BIG_PRIME 1000000007


int main()
{
  string K;
  ull i,j,n,m,D,sum,ans;
  cin >> K >> D;
  sum=0;
  n=K.size();
  for(i=0;i<n;++i)
  {
    sum+=(int)K[i]-(int)'0';
  }
  vector<vector<ull>> dp(2);
  dp[0].resize(D,0);
  dp[1].resize(D);
  dp[0][0]=1;
  if(sum%D)
  {
    ans=BIG_PRIME-1;
  }
  else
  {
    ans=0;
  }
  for(i=0;i<n;++i)
  {
    m=(int)K[n-1-i]-(int)'0';
    sum-=m;
    for(j=0;j<m;++j)
    {
      ans = (ans+dp[0][(100000*D-sum-j)%D])%BIG_PRIME;
    }
    dp[1][D-1]=dp[0][D-1];
    for(j=1;j<=9;++j)
    {
      dp[1][D-1]=(dp[1][D-1]+dp[0][(10*D-1-j)%D])%BIG_PRIME;
    }
    for(j=1;j<D;++j)
    {
      dp[1][D-1-j]=(dp[1][D-j]+dp[0][(10*D-10-j)%D]+BIG_PRIME-dp[0][D-j])%BIG_PRIME;
    }
    for(j=0;j<D;++j)
    {
      dp[0][j]=dp[1][j];
    }
  }
  cout << ans;
  return 0;
}
