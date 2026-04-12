#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = (1 << 30);
	for (int i = 0; i <= max(X, Y); ++i) {
		int reqA = max(X - i, 0);
		int reqB = max(Y - i, 0);
		int cost = A * reqA + B * reqB + C * i * 2;
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}