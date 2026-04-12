#include <bits/stdc++.h>

#define MAXN 3010
#define ll long long
#define mod 998244353

using namespace std;

ll n, tot, ans, s;

ll a[MAXN], f[MAXN]; 

int main() {
	int t;
	scanf("%lld%lld", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = s; j > a[i]; j--) {
			f[j] = (f[j] + f[j - a[i]]) % mod;
		}
		f[a[i]] = (f[a[i]] + i) % mod;
		ans = (ans + (n - i + 1) * f[s] % mod) % mod;
		f[s] = 0;
	}
	cout << (ll)ans << endl;
	return 0;
}