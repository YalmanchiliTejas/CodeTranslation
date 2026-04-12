#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mo 1000000007
typedef long long ll;
using namespace std;
int n;
ll sum[300009],a[300009],ans;
int main()
{
  scanf("%d",&n);sum[0]=0;
  for (int i=1;i<=n;i++)
  {
  	scanf("%lld",&a[i]);
  	sum[i]=(sum[i-1]+a[i])%mo;
  }
  ans=0;
  for (int i=1;i<=n;i++)
  {
  	ans=(ans+(a[i]*(sum[i]-a[i]))%mo)%mo;
  }
  ans=(ans+mo)%mo;
  printf("%lld\n",ans);
  return 0;	
} 