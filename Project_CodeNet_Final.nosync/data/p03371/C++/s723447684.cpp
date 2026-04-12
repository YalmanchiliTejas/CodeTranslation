#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef long long LL;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (X < Y) {
		swap(X, Y);
		swap(A, B);
	}

	int allC = X * 2 * C;
	int AorB = A * X + B * Y;
	int CsAB = Y * 2* C + (X - Y) * A;

	int cmin = min({ allC, AorB, CsAB });

	cout << cmin << endl;

	return 0;
}