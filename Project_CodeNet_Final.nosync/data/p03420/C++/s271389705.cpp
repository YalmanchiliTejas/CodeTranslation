#include <bits/stdc++.h>
#define LL long long

int n, k;
long long ans; 

int main()
{
	scanf("%d%d", &n, &k);
	for(int i=k+1; i<=n; i++)
	{
		ans+=((i-k)*(n/i));
		for(int j=k; j<=n%i; j++) ans++;
	}
	if(k==0) ans-=n;
	printf("%lld\n", ans);
}
