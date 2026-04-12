#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int swap_max = max(X, Y);
	int ans = A * X + B * Y;

	for (int i = 1; i <= swap_max; ++i)
	{
		int cost_a = max((A * (X - i)), 0);
		int cost_b = max((B * (Y - i)), 0);
		int c_ans = cost_a + cost_b + (C * i * 2);
		ans = min(ans, c_ans);
	}

	cout << ans << endl;
	return 0;
}