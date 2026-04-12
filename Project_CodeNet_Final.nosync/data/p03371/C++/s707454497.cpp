#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<cmath>

using namespace std;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans = 0;
	if (C * 2 < A + B)
	{
		ans = C * 2 * min(X, Y);
		if (X < Y)
		{
			if (C * 2 < B)
			{
				ans += C * 2 * (Y - X);
			}
			else
			{
				ans += (Y - X) * B;
			}
		}
		else
		{
			if (C * 2 < A)
			{
				ans += C * 2 * (X - Y);
			}
			else
			{
				ans += (X - Y) * A;
			}
		}
	}
	else
	{
		ans = A * X + B * Y;
	}

	cout << ans << endl;

	return 0;
}