using namespace std;

#include <iostream>

#define MOD 1000000007

int N;

int main() {
	cin >> N;
	long long sum = 0;
	long long ans = 0;
	for(int i = 0;i < N;++i) {
		long long cur;
		cin >> cur;
		ans += (cur * sum) % MOD;
		if(ans >= MOD) ans -= MOD;
		sum += cur;
		if(sum >= MOD) sum -= MOD;
	}
	cout << ans << endl;
	return 0;
}