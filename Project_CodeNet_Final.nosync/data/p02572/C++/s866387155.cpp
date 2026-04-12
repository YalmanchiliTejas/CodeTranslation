#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 10;
const ll mod = 1e9 + 7;
int n;
ll a[N], sum[N], ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	for (int i = n; i >= 1; i--)sum[i] = (sum[i + 1] + a[i]) % mod;
	for (int i = 1; i <= n; i++)ans = (ans + a[i] * sum[i + 1] % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}