#include <bits/stdc++.h>
#include<unordered_map>
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define BUF 50
using namespace std;
ll MOD = 1e9 + 7;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
ll ans = 0;
int main() {
	cin >> A >> B >> C >> X >> Y;
	if (2 * C > A + B) {
		ans = A * X + B * Y;
	}
	else {
		if (X > Y) {
			if (2 * C > A)ans = 2 * C * Y + A * (X - Y);
			else ans = 2 * C * X;
		}
		else {
			if (2 * C > B)ans = 2 * C*X + B * (Y - X);
			else ans = 2 * C*Y;
		}
	}
	cout << ans << endl;
}