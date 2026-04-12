#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	ll n, x, m; cin >> n >> x >> m;
	vector<ll> cnt;
	ll rem = x;
	ll tmp = m;
	while (tmp--) {
		cnt.push_back(rem);
		rem = (ll)pow(rem, 2) % m;
		if (find(cnt.begin(), cnt.end(), rem) != cnt.end())
			break ;
	}
	ll mae = distance(cnt.begin(), find(cnt.begin(), cnt.end(), rem));
	ll maeSUM = accumulate(cnt.begin(), cnt.begin() + mae, 0LL);
	ll loop = cnt.size() - mae;
	ll loopSUM = accumulate(cnt.begin() + mae, cnt.end(), 0LL);
	ll res = 0;
	if (n <= cnt.size())
		res += accumulate(cnt.begin(), cnt.begin() + n, 0LL);
	else {
		res += maeSUM;
		n -= mae;
		ll div = n / loop;
		ll mod = n % loop;
		res += loopSUM * div;
		res += accumulate(cnt.begin() + mae, cnt.begin() + mae + mod, 0LL);
	}
	cout << res << '\n';
    return 0;
}
