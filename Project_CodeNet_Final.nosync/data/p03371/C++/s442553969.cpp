#include <bits/stdc++.h>

using namespace std;

#define rep(i, a) for (int i = 0; i < a; i++)
#define reps(i, a, b) for (int i = a; i < b; i++)

int A, B, C, X, Y;

long long ab()
{
	return A * X + B * Y;
}

long long abc()
{
	if (X < Y) {
		return C * X * 2 + B * (Y - X);
	} else {
		return A * (X - Y) +  C * Y * 2;
	}
}

long long c_all()
{
	return C * max(X, Y) * 2;
}



int main()
{
	cin >> A >> B >> C >> X >> Y;
	long long mi = ab();
	long long t;
	t = abc();
	mi = min(mi, t);
	t = c_all();
	mi = min(mi, t);
	cout << mi << endl;
	return 0;
}