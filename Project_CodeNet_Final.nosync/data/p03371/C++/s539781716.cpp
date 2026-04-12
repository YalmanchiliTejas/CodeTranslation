#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = 1e9;
	for (int i = 0; i <= max(X, Y); ++i) {
		int num = 0;
		num += i * 2 * C;
		num += max(0, X - i)*A;
		num += max(0, Y - i)*B;
		ans = min(num, ans);
	}
	cout << ans << endl;
	return 0;
}