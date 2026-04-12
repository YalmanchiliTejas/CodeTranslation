#include <bits/stdc++.h>

typedef long long int int64;
int64 n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	if(m == 0) {
		printf("%lld\n",n*n);
		return 0;
	}
	int64 ans = 0;
	for(int64 b = m + 1;b <= n;++b) {
		ans += (n + 1) / b * (b - m) + std::max(0LL,(n + 1) % b - m);
	}
	printf("%lld\n",ans);
}
