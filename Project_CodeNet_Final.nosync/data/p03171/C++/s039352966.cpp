#include<iostream>
#include<iomanip>
#include<vector>
typedef unsigned long long ull;
typedef signed long long sll;
using namespace std;

#define INF 0x7FFFFFFFFFFFFFFF
#define BIG_PRIME 1000000007

vector<sll> a;
vector<vector<sll>> dp;

sll get_dp(int l,int r)
{
  if(l==r)return 0;
  if(dp[l][r]==INF)
  {
    dp[l][r]=max(a[l]-get_dp(l+1,r),a[r-1]-get_dp(l,r-1));
  }
  return dp[l][r];
}

int main()
{
  ull i,j,N;
  cin >> N;
  a.resize(N);
  dp.resize(N+1);
  for(i=0;i<=N;++i)
  {
    dp[i].resize(N+1,INF);
    if(i<N)
    {
      cin >> a[i];
    }
  }
  cout << get_dp(0,N);
  return 0;
}