#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	ll ans;

	int H, L, HN, LN;
	if (X >= Y)
	{
		H = A;
		L = B;
		HN = X;
		LN = Y;
	}
	else
	{
		H = B;
		L = A;
		HN = Y;
		LN = X;
	}

	if (A + B > C * 2)
	{
		if (H < C * 2)
		{
			ans = LN * 2 * C + (HN - LN) * H;
		}
		else
		{
			ans = HN * 2 * C;
		}
	}
	else
	{
		ans = X * A + Y * B;
	}

	cout << ans;
}