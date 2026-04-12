#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
#define pb push_back
#define f first
#define s second
#define double long double
const int MAX=2e5+10;
const int MAX2=2e5+4;
const int MAAX=2e18;
const int MOD=1e9+7;
int n,a[3005];
int s1=0,s2=0;
int dp[3005][3005][2];
int fun(int s,int e,bool turn)
{
    if(s>e)
    {
        return 0;
    }
    int &ret=dp[s][e][turn];
    if(ret!=MAAX)
    {
        return ret;
    }
    if(!turn)
    {
        return ret=max(a[s]+fun(s+1,e,!turn),a[e]+fun(s,e-1,!turn));
    }
     return ret=min(-a[s]+fun(s+1,e,!turn),-a[e]+fun(s,e-1,!turn));
}
in main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
  for(int i=0;i<n;++i)
  {
      for(int j=0;j<n;j++)
      {
          for(int k=0;k<2;k++)
          {
              dp[i][j][k]=MAAX;
          }
      }
  }
    cout<<fun(0,n-1,0)<<endl;
    return 0;
}
