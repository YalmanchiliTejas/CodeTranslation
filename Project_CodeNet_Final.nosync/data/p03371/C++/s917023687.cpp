#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e8;

signed main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = 0;
	if (A + B >= 2 * C) {
		int common = min(X, Y);
		ans += common * C * 2;
		if (X > Y) {
			if (A >= 2 * C)ans += (X - common) * C * 2;
			else ans += (X - common) * A;
		}
		else if (X < Y) {
			if (B >= C * 2)ans += (Y - common) * C * 2;
			else ans += (Y - common) * B;
		}
	}
	else ans = A * X + B * Y;
	cout << ans;
}