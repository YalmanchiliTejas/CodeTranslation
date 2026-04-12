#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans = A*X + B*Y;
	for (int c = 0; c <= max(X, Y); c++) {
		int nX = max(0, X - c);
		int nY = max(0, Y - c);
		int nZ = 2 * c;
		ans = min(ans, A*nX + B*nY + C * nZ);
	}

	cout << ans << endl;
}