#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	if (A+B < 2*C) {
		cout << X*A + Y*B << '\n';
	} else {
		int cnt = 2 * min(X, Y);
		cout << min(2 * max(X, Y) * C, cnt*C + A*(X-cnt/2) + B*(Y-cnt/2)) << '\n';
	}

	return 0;
}
