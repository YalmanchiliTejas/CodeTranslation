#include<bits/stdc++.h>
using namespace std;

const int N = 200009, Mod = 1000000007;
int n, a[N], sum[N], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]), sum[i] = (a[i] + sum[i - 1]) % Mod;
	for (int i = 1; i <= n; ++ i) 
		ans = (ans + 1LL * a[i] * (sum[n] - sum[i] + Mod) % Mod) % Mod;
	printf("%d\n", ans);
	return 0;
}