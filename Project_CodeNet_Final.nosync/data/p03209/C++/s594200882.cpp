#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N; long long X;
	cin >> N >> X;
	vector<long long> a(N + 1), b(N + 1);
	a[0] = 1, b[0] = 1;
	for (int i = 1; i <= N; ++i) {
		a[i] = 2 * a[i - 1] + 3;
		b[i] = 2 * b[i - 1] + 1;
	}
	long long ans = 0;
	for (int i = N - 1; i >= 0 && X > 0; --i) {
		--X;
		if (X >= a[i]) {
			X -= a[i];
			ans += b[i];
			if (X >= 1) {
				--X;
				++ans;
				if (X >= a[i]) {
					X -= a[i];
					ans += b[i];
					if (X >= 1) --X;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}