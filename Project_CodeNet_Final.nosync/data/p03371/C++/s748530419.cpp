#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, X, Y;
	int ans = 0;
	cin >> A >> B >> C >> X >> Y;

	if(A + B <= 2 * C) {
		ans = A * X + B * Y;
	} else {
		int c = 0;
		while(X - c / 2 && Y - c / 2) {
			ans += 2 * C;
			c += 2;
		}
		ans += A * (X - c / 2) + B * (Y - c / 2);
	}
	
	int ans2 = C * max(X, Y) * 2;

	cout << min(ans, ans2) << endl;

	return 0;
}
