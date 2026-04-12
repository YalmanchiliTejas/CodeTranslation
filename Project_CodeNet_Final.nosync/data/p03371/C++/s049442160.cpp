#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if (2 * C >= A + B) {
		cout << X * A + Y * B << endl;
		return 0;
	}
	if (X > Y && A <= 2 * C) {
		cout << (X - Y) * A + Y * 2 * C << endl;
		return 0;
	}
	if (X < Y && B <= 2 * C) {
		cout << X * 2 * C + (Y - X) * B << endl;
		return 0;
	}
	cout << max(X, Y) * 2 * C << endl;
	return 0;
}	
