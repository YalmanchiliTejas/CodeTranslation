#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int s = min(A + B, C * 2);
	int a, b;
	a = s * min(X, Y);
	b = 0;

	if (X > Y) {
		b = (X - Y) * min(A, C * 2);
	}
	else if (X < Y) {
		b = (Y - X) * min(B, C * 2);
	}

	cout << a + b << endl;
}