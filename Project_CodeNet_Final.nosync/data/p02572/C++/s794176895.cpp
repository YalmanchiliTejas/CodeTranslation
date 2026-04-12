//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+5, mod = 1e9+7;

ll n, a[N], s[N], ans;

int main() {
	scanf("%lld", &n);
	for(int i=1;i<=n;i++) {
		scanf("%lld", &a[i]);
		s[i] = (s[i-1] + a[i]) % mod;
	}
	for(int i=1;i<=n;i++) ans = (ans + s[i-1] * a[i]) % mod;
	printf("%lld\n", ans);
	return 0;
}