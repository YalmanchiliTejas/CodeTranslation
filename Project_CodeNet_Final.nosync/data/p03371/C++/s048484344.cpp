#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	c *= 2;
	long long ans = (long long)1e10;
	for (long long i = 0; i <= max(x,y); i++) {
		ans = min(ans, c * i + max(0LL, x - i) * a + max(0LL, y - i) * b);
	}
	cout << ans << endl;

	return 0;
}