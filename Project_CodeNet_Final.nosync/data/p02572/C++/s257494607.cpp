#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int Mod=1e9+7;
long long a[2000010],sum[2000010],n,i,ans;
int main () {
	scanf ("%lld",&n);
	for (i=1;i<=n;i++) 
		scanf ("%lld",&a[i]),sum[i]=sum[i-1]+a[i],sum[i]%=Mod;
	for (i=1;i<n;i++)
		ans=(ans+a[i]%Mod*(sum[n]-sum[i]+Mod)%Mod)%Mod;
	printf ("%lld\n",ans);
	return 0;
}