#include <bits/stdc++.h>

using namespace std;

int a, b, c, x, y, ans;

int main() {
    cin >> a >> b >> c >> x >> y;
    if (2 * c < a + b) {
	int mn = min(x, y);
	ans += 2 * mn * c;
	x -= mn;
	y -= mn;
    }
    return cout << ans + min(a, 2 * c) * x + min(b, 2 * c) * y, 0;
}