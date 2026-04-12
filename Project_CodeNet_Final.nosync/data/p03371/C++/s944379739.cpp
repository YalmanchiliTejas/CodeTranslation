#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = 0;
	if (A + B < 2 * C) {
		cout << A * X + B * Y << endl;
	}
	else {
		ans += min(X, Y) * 2 * C;
		int num = 0;
		if (X > Y) {
			num = X - Y;
			if (A < 2 * C) ans += num * A;
			else ans += num * 2 * C;
		}
		else {
			num = Y - X;
			if (B < 2 * C) ans += num * B;
			else ans += num * 2 * C;
		}
		cout << ans << endl;
	}
}