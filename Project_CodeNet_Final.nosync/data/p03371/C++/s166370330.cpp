#include <bits/stdc++.h>
using namespace std;
int main() {
	long long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	long long ans1 = A * X + B * Y;
	long long ans2 = C * min(X, Y) * 2;
	if (X < Y) ans2 += B * (Y - X);
	else ans2 += A * (X - Y);
	long long ans3 = C * max(X, Y) * 2;
	long long Ans = min({ans1, ans2, ans3});
	cout << Ans << endl;
}