#include"bits/stdc++.h"
using namespace std;


int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans=0;
	if (A > C * 2 && B > C * 2) {
		ans = C*2 * max(X,Y);
	}
	else if (A + B > C * 2) {
		if (X > Y) {
			ans += C*2 * Y;
			X -= Y;
			if (A > C * 2)
				ans += C*2 * X;
			else
				ans += A * X;
		}
		else {
			ans += C*2 * X;
			Y -= X;
			if (B > C * 2)
				ans += C*2 * Y;
			else
				ans += B * Y;
		}
	}
	else {
		ans += A*X + B*Y;
	}

	cout << ans << endl;
}