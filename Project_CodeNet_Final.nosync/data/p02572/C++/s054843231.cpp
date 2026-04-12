#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>;
using namespace std;

int main() {
	
	int n;
	cin >> n;

	long long MOD = 1e9 + 7;

	vector<int> vec(n);
	vector<int> sum(n);
	for (int i = 0;i < n;i++) {
		cin >> vec[i];
		if(i==0) sum[0] = vec[0];
		if (i > 0)sum[i] = vec[i] + sum[i - 1];
		sum[i] %= MOD;
	}
	

	long long ans=0;
	for (int i = 0;i < n;i++) {
		long long k = sum[n - 1] - sum[i];
		if (k < 0)k += MOD;
		ans += vec[i] * (k);
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}