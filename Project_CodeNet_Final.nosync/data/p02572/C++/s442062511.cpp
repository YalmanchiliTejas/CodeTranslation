#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> v;
long long ans;
const int MOD = 1e9 + 7;
int main() {
	int n;
	cin >> n;

	// 1 3 6
	// 5 * 1 + 3*2
	vector<long long> v(n);
	for (auto& i : v) cin >> i;
	vector<long long> partSum(n);
	partSum[0] = v[0];
	for (int i = 0; i < v.size(); ++i) {
		partSum[i] = (i-1 >= 0 ? partSum[i - 1] : 0 ) + v[i];
	}
	for (int i = 0; i < v.size(); ++i) {
		long long sum = (partSum[n - 1] - partSum[i])%MOD;
		ans += v[i] * sum;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;

}