#include "cstring"
#include "iostream"

using namespace std;

int main()
{
	int A, B, C, X, Y,a,b;
	cin >> A >> B >> C >> X >> Y;
	int min,max,money=0;
	int t;
	int moneymin=0;
	if (X > Y)
		max = X;
	else
		max = Y;

	for (t = 0; t < max+1; t++) {
		money = 0;

		money += t * 2 * C;
		if((X-t)>0)
		money += A * (X - t);
		if((Y-t)>0)
		money += B * (Y - t);

		if (t == 0)
			moneymin = money;

		if (money < moneymin)
			moneymin = money;

	}

	cout << moneymin;

	return 0;
}