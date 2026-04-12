#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef map<int, ll> mill;
typedef vector<mill> vmill;

int main() {FIN
	
	ll n, i, m, j, res = -1000000000000000000;
	cin >> n;
	m = n / 2;
	vll ns(n);
	for (i = 0; i < n; i++)
		cin >> ns[i];
	
	vmill dp(n);
	dp[0][1] = ns[0];
	dp[1][1] = ns[1];
	if (m == 1)
		res = max(ns[0], ns[1]);
	for (i = 2; i < n; i++) {
		j = ((i + 2 <= n ? (n - i) : 0) + 1) / 2;
		if (j + 1 >= m) {
			dp[i][1] = ns[i];
			if (m == 1)
				res = max(res, ns[i]);
		}
		for (auto it = dp[i - 2].begin(); it != dp[i - 2].end(); it++) {
			if (j + 1 + it->first >= m) {
				auto jt = dp[i].find(it->first + 1);
				if (jt != dp[i].end())
					jt->second = max(jt->second, ns[i] + it->second);
				else
					dp[i][it->first + 1] = ns[i] + it->second;
				if (m == it->first + 1)
					res = max(res, dp[i][it->first + 1]);
			}
		}
		if (i - 3 >= 0) {
			for (auto it = dp[i - 3].begin(); it != dp[i - 3].end(); it++) {
				if (j + 1 + it->first >= m) {
					auto jt = dp[i].find(it->first + 1);
					if (jt != dp[i].end())
						jt->second = max(jt->second, ns[i] + it->second);
					else
						dp[i][it->first + 1] = ns[i] + it->second;
					if (m == it->first + 1)
						res = max(res, dp[i][it->first + 1]);
				}
			}
		}
		if (i - 4 >= 0) {
			for (auto it = dp[i - 4].begin(); it != dp[i - 4].end(); it++) {
				if (j + 1 + it->first >= m) {
					auto jt = dp[i].find(it->first + 1);
					if (jt != dp[i].end())
						jt->second = max(jt->second, ns[i] + it->second);
					else
						dp[i][it->first + 1] = ns[i] + it->second;
					if (m == it->first + 1)
						res = max(res, dp[i][it->first + 1]);
				}
			}
		}
		
	}
	
	cout << res << "\n";
	
	return 0;
}
