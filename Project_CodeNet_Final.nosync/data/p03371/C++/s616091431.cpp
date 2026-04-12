#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int result = 0;

	// 単品よりもABピザを買う方がお得なら、買えるだけ買ってしまう
	if (a + b > 2 * c) {
		while (x != 0 && y != 0) {
			x--;
			y--;
			result += 2 * c;
		}
	}

	// 残りのAピザ・Bピザの補填
	if (x != 0) {
		if (a < 2 * c) {
			result += a * x;
		} else {
			result += 2 * c * x;
		}
	}
	if (y != 0) {
		if (b < 2 * c) {
			result += b * y;
		} else {
			result += 2 * c * y;
		}
	}

	cout << result << endl;
}
