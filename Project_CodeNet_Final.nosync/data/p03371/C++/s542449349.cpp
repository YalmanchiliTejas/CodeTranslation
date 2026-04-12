#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

int main() {
	int A, B, C, X, Y, i, j, k;
	int W = 15000000000;
	cin >> A >> B >> C >> X >> Y;

	for (i = 0; i <= 100000; i++) {
		int a, b;
		a = max(0, X - i);
		b = max(0, Y - i);
		int Z = A * a + B * b + C * 2 * i;
		W = min(W, Z);
	}
	cout << W << endl;
	return 0;
}


