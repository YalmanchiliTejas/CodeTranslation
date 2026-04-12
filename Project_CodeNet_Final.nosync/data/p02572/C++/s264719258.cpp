#include <bits/stdc++.h>
#define maxn 202333
#define mod 1000000007ll
using namespace std;
typedef long long ll;
ll a[maxn], s[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1, x; i <= n; ++i) scanf("%d", &x), a[i] = x;
	for(int i = n; i >= 1; --i) s[i] = (s[i + 1] + a[i]) % mod;
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = (ans + a[i] * s[i + 1]) % mod;
	}
	printf("%d", (int) ans);
	return 0;
}