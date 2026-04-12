#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = A * X + B * Y;
	for (int i = 0; i <= max(X, Y); i++) {
		int tmp = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
		if (ans > tmp) {
			ans = tmp;
		}
	}
	cout << ans << endl;
}