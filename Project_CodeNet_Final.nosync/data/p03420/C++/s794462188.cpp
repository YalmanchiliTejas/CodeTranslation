#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <map>
using namespace std;

long long N, K, sum;

int main() {
	cin >> N >> K;
	if (K == 0) {
		cout << N*N << endl;
		return 0;
	}
	for (int i = K + 1; i <= N; i++) {
		long long D = (N + 1) / i;
		long long E = D*(i - K);
		long long F = (N + 1) % i;
		long long G = max(0LL, F - K);
		sum += E + G;
	}
	cout << sum << endl;
	return 0;
}