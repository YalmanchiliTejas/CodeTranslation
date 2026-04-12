#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	ll n, x, m;
	cin >> n >> x >> m;

	unordered_map<ll, ll> seen;
	seen[x] = 1;

	vector<ll> pref(100001);
	pref[0] = 0;
	pref[1] = x;

	ll stc = 1, endc = n;
	ll pf = x, f;

	bool flag = false;

	ll res = x;

	for (ll i = 2; i <= n; i++) {
		f = (pf * pf) % m;

		if (seen.count(f)) {

			// deb(i);


			endc = i-1;
			stc = seen[f];
			flag = true;
			break;
		}


		pref[i] = f + pref[i-1];
		seen[f] = i;
		pf = f;
		res += f;

		// deb(i);
		// deb(f);

	}

	// ll res = 0;
	if (flag) {

		// deb(stc);
		// deb(endc);

		res = pref[stc-1];

		// deb(res);

		ll rem = n-stc+1;

		// deb(rem);

		ll sumc = pref[endc] - pref[stc-1];

		// deb(sumc);

		ll lenc = endc - stc + 1;

		// deb(lenc);

		
		ll times = rem / lenc;

		// deb(times);

		res += times * sumc;

		// deb(res);

		ll modc = rem % lenc;

		// deb(modc);

		res += pref[stc+modc-1] - pref[stc-1];
	}

	cout << res;

	return 0;
}