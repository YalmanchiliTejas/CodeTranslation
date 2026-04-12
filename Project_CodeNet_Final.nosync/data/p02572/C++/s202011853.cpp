#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	vector<long long> ar(n);
	long long sum = 0;
	for(int i = 0;i < n;i++){
		scanf("%lld", &ar[i]);
		sum += ar[i];
	}
	int ans = 0;
	for(int i = 0;i < n - 1;i++){
		sum -= ar[i];
		ans += ((ar[i] * (sum % MOD)) % MOD);
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}
//ios_base::sync_with_stdio(false);
//cin.tie(0);
//tod-ngen
