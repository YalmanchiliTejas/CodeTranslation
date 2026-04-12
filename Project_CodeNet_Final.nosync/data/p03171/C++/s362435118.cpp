#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define vi vector<int>
#define loop(i, n) for(int i=1;i<=n;i++)
#define loop0(i, n) for(int i=0;i<n;i++)
#define in(i) scanf("%lld", &i);
#define out(i) printf("%d", i)

long long int n, k, a[3001];
long long int dp[3001][3001][3];

long long int solve(long long int l, long long int r, int ch)
{
  if(dp[l][r][1+ch]!=-1)
    return dp[l][r][1+ch];
  if(l==r)
    return dp[l][r][1+ch]=ch*a[l];
  if(ch==-1)
  {
    if(l>r)
      return INT_MIN;
    if(l==r)
      return -a[l];
    return dp[l][r][1+ch]=min(solve(l+1, r, 1)-a[l], solve(l, r-1, 1)-a[r]);
  }
  else
  {
    if(l>r)
      return INT_MAX;
    if(l==r)
      return a[l];
    return dp[l][r][1+ch]=max(solve(l+1, r, -1)+a[l], solve(l, r-1, -1)+a[r]);
  }
}
int main()
{
  memset(dp, -1, sizeof(dp));
  in(n);
  loop(i, n)
  {
    in(a[i]);
  }
  if(n==1)
    cout<<a[1]<<"\n";
  else
  {
    long long int ans=max(solve(2, n, -1)+a[1], solve(1, n-1, -1)+a[n]);
    cout<<ans<<"\n";
  }
}

