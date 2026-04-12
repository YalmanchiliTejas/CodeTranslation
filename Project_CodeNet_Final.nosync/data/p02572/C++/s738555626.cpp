#include<bits/stdc++.h>
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int n, sum, ans, a[maxn];

int main() {
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = n; i; --i) {
		(ans += 1ll * a[i] * sum % mod) %= mod;
		(sum += a[i]) %= mod;
	}
	cout << ans;
	return 0;
}