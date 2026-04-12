#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int res = INT_MAX;
	for (int i = 0; i <= max(x, y) * 2; i += 2) {
		int t = c * i;
		t += max(0, x - i / 2) * a;
		t += max(0, y - i / 2) * b;
		res = min(res, t);
	}
	cout << res << endl;
}