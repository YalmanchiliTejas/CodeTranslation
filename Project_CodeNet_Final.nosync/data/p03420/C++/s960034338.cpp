#include <iostream>
#include <algorithm>

using namespace std;

long long int N, K, ans = 0;

int main() {
	cin >> N >> K;
	for (int i = K + 1; i <= N; i++) {
		if (N%i == 0) {
			ans += N / i*(i - K);
		}
		else {
			ans += N / i*(i - K) + N%i - min(N%i, max((long long int)0, K - 1));
		}
	}
	cout << ans << endl;
	return 0;
}