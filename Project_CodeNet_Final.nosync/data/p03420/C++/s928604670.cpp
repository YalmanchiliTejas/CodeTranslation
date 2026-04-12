#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>

using namespace std;

long long a,b,n,k,ans;

int main()
{
  scanf("%lld%lld",&n,&k);
  if (k==0) {
  	cout<<n*n;
  	return 0;
  }
  for (int i=k+1;i<=n;i++)
  {
  	ans+=(n/i)*(i-k)+max((n%i-k+1),(long long)0);
  }
  cout<<ans;
  return 0;
}
