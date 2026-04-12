#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5,MOD = 998244353;
#define int long long
int n,s;
int a[N],f[N];
int ans;
signed main() {
	scanf("%lld%lld",&n,&s);
	for(int i = 1;i <= n;++i)
		scanf("%lld",a+i);
	f[a[1]] = 1;
	for(int i = 2;i <= n;++i) {
		for(int j = s;j > a[i];--j)
			(f[j] += f[j-a[i]]) %= MOD;
		(f[a[i]] += i) %= MOD;
		(ans += f[s] % MOD) %= MOD;
	}
	printf("%lld\n",ans);
	return 0;
}

