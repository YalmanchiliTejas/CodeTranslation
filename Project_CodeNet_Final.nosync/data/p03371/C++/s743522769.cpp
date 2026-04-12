#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int res = A * X + B * Y;
	C *= 2;
	for (int i = 0; i <= max(X, Y); i++) {
		int total = C * i + A * max(0, X - i) + B * max(0, Y - i);
		res = min(res, total);
	}
	cout << res << endl;
	return 0;
}