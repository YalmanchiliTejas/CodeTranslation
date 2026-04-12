#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long ans = 0;

int main()
{
	scanf("%lld %lld", &n, &k);
	if(k == 0) printf("%lld\n", n * n);
	else {
		for(register int i = max(k, 1ll); i <= n; ++i){
			ans += (n / i) * (i - k) + (n % i >= k ? n % i - k + 1 : 0);
		}
		printf("%lld\n", ans);
	}
	return 0;
}