#include <iostream>
#include <algorithm>	
using namespace std;
#define ll long long

ll r[99], p[99];

ll ps(int n, ll k) {
	if (k == 0) return 0;
	if (n == 0) return 1;
	if (k == 1) return 0;
	if (k <= r[n - 1] + 1)
		return ps(n - 1, k - 1);
	else if (k == r[n - 1] + 2)
		return p[n - 1] + 1;
	else if (k <= r[n - 1] * 2 + 2)
		return p[n - 1] + ps(n - 1, k - r[n - 1] - 2) + 1;
	else
		return p[n - 1] * 2LL + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; ll k; cin >> n >> k;
	r[0] = p[0] = 1;
	for (int i = 1; i <= n; i++) {
		r[i] = r[i - 1] * 2 + 3; p[i] = p[i - 1] * 2 + 1;
	}
	cout << ps(n, k) << '\n';
	return 0;
}