#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, x, A[50176];
int main() {
	// step #1. read input
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int H = (N >> 1);
	for (int i = 0; i < H; ++i) {
		cin >> A[i];
	}
	if (N % 2 == 1) {
		cin >> x;
	}
	for (int i = H - 1; i >= 0; --i) {
		cin >> x;
		A[i] += x;
	}
	// step #2. calculate the answer
	long long ans = 0;
	for (int i = 1; i < N; ++i) {
		long long sum = 0;
		int pos = i;
		while (pos < H) {
			sum += A[pos];
			ans = max(ans, sum);
			pos += i;
		}
		if ((N - 1) % i != 0) {
			pos = (N - 1) - pos;
			while (pos >= i) {
				sum += A[pos];
				ans = max(ans, sum);
				pos -= i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}