#include<iostream>
using namespace std;

int main() {
	int A, B, C, X, Y;
	long long ans, tmp;
	cin >> A >> B >> C >> X >> Y;
	int n;
	if (X >= Y)n = X;
	else n = Y;
	int i;
	tmp = 0;
	ans = 2 * C * n;
	for (i = n - 1;i >= 0;i--) { //cを2i枚
		tmp += 2 * i * C;
		if (X - i > 0)tmp += A * (X - i);
		if (Y - i > 0)tmp += B * (Y - i);
		if (tmp < ans) ans = tmp;
		tmp = 0;
	}
	cout << ans << endl;
}