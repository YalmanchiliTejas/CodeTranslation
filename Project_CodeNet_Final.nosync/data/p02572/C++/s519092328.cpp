#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int64_t> v(n + 1);
	for(int i = 1; i <= n; i++) cin >> v[i];
	vector<int64_t> sum(n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + v[i];
	}
	int64_t T = 0;
	for(int i = 1; i <= n - 1; i++){
		T += v[i] * (sum[n] % MOD - sum[i] % MOD + MOD) % MOD;
		T %= MOD;
	}
	cout << T << '\n';
	return 0;
}