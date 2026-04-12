#include <algorithm>
#include <iostream>
using namespace std;

int A, B, C, X, Y;
long long ans;

int main() {
	cin >> A >> B >> C >> X >> Y;
	C *= 2;
	if (C < A + B) {
		ans += min(X, Y) * C;
		int mn = min(X, Y);
		X -= mn;
		Y -= mn;
	}
	ans += X * min(C, A) + Y * min(C, B);
	cout << ans;
}