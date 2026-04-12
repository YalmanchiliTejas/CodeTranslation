#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main() {
	unsigned long long N;
	cin >> N;
	vector<unsigned long long> A(N);
	for (unsigned long long i = 0; i < N; i++)cin >> A[i];
	sort(A.rbegin(), A.rend());
	unsigned long long ans = 0, ans2 = 0;
	for (unsigned long long i = 0; i < N; i++) {
		if (N % 2 == 0) {
			if (i < N / 2 - 1)ans += 2 * A[i];
			else if (i == N / 2 - 1)ans += A[i];
			else if (i == N / 2)ans -= A[i];
			else ans -= 2 * A[i];
		}
		if (N % 2 == 1) {
			if (i < N / 2 - 1)ans += 2 * A[i];
			else if (i == N / 2 - 1 || i == N / 2)ans += A[i];
			else ans -= 2 * A[i];
		}
	}
	for (unsigned long long i = 0; i < N; i++) {
		if (N % 2 == 1) {
			if (i < N / 2)ans2 += 2 * A[i];
			else if (i == N / 2 || i == N / 2 + 1)ans2 -= A[i];
			else ans2 -= 2 * A[i];
		}
	}
	ans = max(ans, ans2);
	cout << ans << endl;
}