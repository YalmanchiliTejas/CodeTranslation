#include <iostream>
using namespace std;

int main() {
	int N;
	long X, L[51] = {1}, P[51] = {1}, ans = 0;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		L[i + 1] = L[i] * 2 + 3;
		P[i + 1] = P[i] * 2 + 1;
	}
	while (N >= 0) {
		if (N == 0) {
			++ans;
			break;
		}
		if (X == 1) break;
		if (X == L[N]) {
			ans += P[N];
			break;
		}
		if (X == L[N] / 2 + 1) {
			ans += P[N - 1] + 1;
			break;
		}
		if (X > L[N] / 2 + 1) {
			ans += P[N - 1] + 1;
			X -= L[N - 1] + 2;
		}
		else --X;
		--N;
	}
	cout << ans;
}