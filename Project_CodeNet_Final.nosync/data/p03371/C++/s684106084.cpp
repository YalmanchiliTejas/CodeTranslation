#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	C *= 2;
	int	total;
	if (A + B > C)
	{
		while (X > 0 && Y > 0)
		{
			total += C;
			X--;
			Y--;
		}
	}
	if (A > C)
	{
		while (X > 0)
		{
			total += C;
			X--;
		}
	}
	if (B > C)
	{
		while (Y > 0)
		{
			total += C;
			Y--;
		}
	}
	while (X > 0)
	{
		total += A;
		X--;
	}
	while (Y > 0)
	{
		total += B;
		Y--;
	}
	cout << total << endl;
}
