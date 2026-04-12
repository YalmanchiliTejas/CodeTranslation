#include <algorithm>
#include <iostream>

using namespace std;

const int N = 50;

long long aa[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	long long ans = 0;
	while (true) {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			long long cnt = aa[i] / n;
			sum += cnt;
		}
		if (sum == 0) {
			cout << ans << '\n';
			return 0;
		}
		ans += sum;
		for (int i = 0; i < n; i++) {
			long long cnt = aa[i] / n;
			aa[i] = aa[i] % n + sum - cnt;
		}
	}
	return 0;
}
