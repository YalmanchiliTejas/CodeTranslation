#include<bits/stdc++.h>
typedef long long int ll;
#define mod 1000000007
#define sz 200009
ll n,m,i,j,k,l,t,arr[sz],dp[sz],brr[sz],crr[sz],drr[sz],err[sz];
int main()
{
  scanf("%lld",&n);
  for(i=1;i<=n;i++)
    scanf("%lld",&arr[i]);
  for(i=1;i<=n;i++)
  {
      if(i%2==1)
      {
          dp[i]=dp[i-2]+arr[i];
          brr[i]=dp[i-1]>brr[i-2]+arr[i]?dp[i-1]:brr[i-2]+arr[i];
          crr[i]=brr[i-1]>crr[i-2]+arr[i]?brr[i-1]:crr[i-2]+arr[i];
      }
      else
      {
           dp[i]=dp[i-2]+arr[i]>dp[i-1]?dp[i-2]+arr[i]:dp[i-1];
          brr[i]=brr[i-1]>brr[i-2]+arr[i]?brr[i-1]:brr[i-2]+arr[i];
          crr[i]=crr[i-1]>crr[i-2]+arr[i]?crr[i-1]:crr[i-2]+arr[i];
      }
  }
  if(n%2==1)
    k=brr[n];
  else
    k=dp[n];
  printf("%lld\n",k);
}
