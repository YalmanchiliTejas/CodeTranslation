#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0, answer=1e9;
	for (int i = 0; i <= 100000; i++) {
		if (x > i) {
			ans += a * (x - i);
		}
		if (y > i) {
			ans += b * (y - i);
		}
		ans += i * 2 * c;
		answer = min(answer, ans);
		ans = 0;
	}
	cout << answer << endl;
	return 0;
}