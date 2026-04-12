#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const lint N = 2e5+5, mod = 1e9+7;
lint n, a[N];

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif
	
	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	lint sum = a[n-1], ans = 0;

	for (int i = n-2; i >= 0; i--){
		int add = (a[i] * sum)%mod;
		ans = (ans + add)%mod;
		sum = (sum + a[i])%mod;
	}

	printf("%lld\n", ans);

	return 0;
}