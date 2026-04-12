#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long LL;


int main(void) {

	LL A, B, C, X, Y, m1, m2, m3;

	cin >> A >> B >> C >> X >> Y;

	m1 = A * X + B * Y;

	m2 = 2 * C * max(X, Y);

	if (X < Y)
		m3 = 2 * C * X + (Y - X) * B;
	else
		m3 = 2 * C * Y + (X - Y) * A;


	cout << min({ m1,m2,m3 }) << endl;

	return 0;
}
