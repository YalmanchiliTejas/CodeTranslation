#include "iostream"
using namespace std;

int main()
{
	int A, B, C, X, Y,money;
	cin >> A >> B >> C >> X >> Y;
	
	if (A + B < 2 * C) money=(A*X + B*Y);
	else if (X < Y) {
		if (C * 2 * X + (Y - X)*B < C*2*Y)money = C * 2 * X + (Y - X)*B;
		else money = 2*C*Y;
	}
	else {
		if (C * 2 * Y + (X - Y)*A < C*2*X)money = C * 2 * Y + (X - Y)*A;
		else money = 2*C*X;
	}
	cout << money << endl;
	return 0;
}
