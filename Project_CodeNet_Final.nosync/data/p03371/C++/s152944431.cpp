#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = 0;
	if (A + B < C * 2) {
		ans += min(X, Y) * (A + B);
	}
	else {
		ans += min(X, Y) * C * 2;
	}
	if (X > Y) {
		if (A < C * 2) {
			ans += A * (X - Y);
		}
		else {
			ans += C * 2 * (X - Y);
		}
	}
	else {
		if (B < C * 2) {
			ans += B * (Y - X);
		}
		else {
			ans += C * 2 * (Y - X);
		}
	}
	cout << ans << endl;
}