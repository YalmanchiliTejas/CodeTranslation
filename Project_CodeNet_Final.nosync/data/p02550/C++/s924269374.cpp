#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;
ll n, x, m;
ll binpow(ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow(a, n - 1) * a) % m;
	else {
		ll b = binpow(a, n / 2);
		return (b * b) % m;
	}
}

ll kek() {
	ll curM = x;
	ll ans = x;

	map<ll, ll> t;
	map<ll, ll> s;
	t[x] = 0;
	s[x] = 0;

	ll lft = 0;
	for (int i = 1; i < n; i++) {
		if (i == n - 3) {
			cout << "";
		}
		curM = binpow(curM, 2);
		ans += curM;
	}

	return ans;
}

int main()
{
	fastInp;

	ll ans = 0;

	cin >> n >> x >> m;

	ll curM = x;
	ans = x;
	
	map<ll, ll> t;
	map<ll, ll> s;
	t[x] = 0;
	s[x] = 0;
	
	ll lft = 0;

	for (int i = 1; i < n; i++) {
		curM = binpow(curM, 2);
		if (t.find(curM) != t.end()) {
			ll cycl = i - t[curM];
			lft = (n - i - 1) % cycl; ll q = (n - i - 1) / cycl;
			ll curS = s[curM], pr = ans;
			ans += q * (pr - curS);
			ans += curM;
			break;
		}
		t[curM] = i;
		s[curM] = ans;
		ans += curM;
		
		
	}

	
	for (int i = 0; i < lft; i++) {
		curM = binpow(curM, 2);
		ans += curM;
	}

	cout << ans;

	return 0;
}