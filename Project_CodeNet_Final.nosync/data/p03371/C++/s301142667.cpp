#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (X > Y)
		cout << min(A + B, C * 2)*Y + min(A, C * 2)*(X - Y) << endl;
	else
		cout << min(A + B, C * 2)*X + min(B, C * 2)*(Y - X) << endl;

	return 0;
}