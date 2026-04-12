#include <bits/stdc++.h>

using namespace std;

#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(x)  (x).begin(), (x).end()
#define ll long long

vector<ll> a(1, 1), p(1, 1);

ll dfs(ll n, ll x) {
	if (n == 0)
		return (x <= 0) ? 0 : 1;
	else if (x <= 1 + a[n-1])
		return dfs(n-1, x-1);
	else
		return p[n-1] + 1 + dfs(n-1, x-2-a[n-1]);
}

int main()
{
	ll n, x;

	cin >> n >> x;

	rep (i, n) {
		a.push_back(a[i] * 2 + 3);
		p.push_back(p[i] * 2 + 1);
	}

	cout << dfs(n, x) << endl;
}

