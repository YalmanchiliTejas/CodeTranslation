#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

ll a[101], p[101];

ll f(int n, ll x) {
	if (n == 0) {
		if (x == 0)
			return 0;
		else
			return 1;
	}

	if (x == 0)
		return 0;

	if (x <= 1 + a[n - 1])
		return f(n - 1, x - 1);
	else
		return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);

}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int n;
	ll x;
	cin >> n >> x;

	a[0] = p[0] = 1;
	rep (i, 1, n) {
		a[i] = 2 * a[i - 1] + 3;
		p[i] = 2 * p[i - 1] + 1;
	}

	cout << f(n, x) << endl;

	return 0;
}
