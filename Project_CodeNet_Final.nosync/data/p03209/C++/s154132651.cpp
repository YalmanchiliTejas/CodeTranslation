#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> a(51);  //レベルNバーガーの層
vector<ll> b(51);  //レベルNバーガーのパティ

ll f(ll l,ll x) {
	if (l == 0) return b[0];
	else if (x == 1) return 0;
	else if (2 <= x && x <= a[l-1]+1) return f(l-1,x-1);
	else if (x == a[l-1]+2) return b[l-1]+1;
	else if (a[l-1]+3 <= x && x <= a[l]-1) return b[l-1]+1+f(l-1,x-a[l-1]-2);
	else return b[l];
}

int main() {

	a[0] = 1;
	b[0] = 1;

	for (ll i=1;i<=50;i++) {
		a[i] = 2*a[i-1]+3;
		b[i] = 2*b[i-1]+1;
	}

	ll n,x;
	cin >> n >> x;
	ll ans = f(n,x);
	cout << ans << endl;
	return 0;
}
