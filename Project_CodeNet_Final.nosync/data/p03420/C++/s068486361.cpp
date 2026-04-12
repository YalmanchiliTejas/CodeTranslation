#include <iostream>
#include <algorithm>
using namespace std;
int N, K; long long ret;
int main() {
	cin >> N >> K;
	for (int i = K + 1; i <= N; i++) {
		ret += 1LL * (N / i) * (i - K) + max(N % i - K + 1, 0);
	}
	cout << ret - (K == 0 ? N : 0) << endl;
	return 0;
}