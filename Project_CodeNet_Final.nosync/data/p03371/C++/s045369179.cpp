#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, x, y, answer = 0;
	cin >> a >> b >> c >> x >> y;
	while (x >= 1 || y >= 1) {
		if (x >= 1 && y >= 1) {
			answer += min(c * 2, a + b);
			x--;
			y--;
		}
		else if (x >= 1) {
			answer += min(c * 2, a);
			x--;
		}
		else if (y >= 1) {
			answer += min(c * 2, b);
			y--;
		}
	}
	cout << answer << endl;
	return 0;
}