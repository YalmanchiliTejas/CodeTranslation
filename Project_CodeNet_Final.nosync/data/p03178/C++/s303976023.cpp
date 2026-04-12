#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long int
#define F first
#define S second
#define pll pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vpii vector<pair<int,int> >
#define vvpii vector<vpii >
#define vpll vector<pair<ll,ll> >
#define vvpll vector<vpll >
#define pb push_back
#define MOD 1000000007
#define brk cout<<"\n"

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

struct compare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		if ((a.S - a.F) != (b.S - b.F)) return ((a.S - a.F) > (b.S - b.F));
		else return (a.F < b.F);
	}
};

void add_self(ll &a, ll b) {
	a += b;
	if (a >= MOD)a -= MOD;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	FASTIO;
	string k; cin >> k;
	ll len = k.length(), d; cin >> d;
	vvl dp(d, vl(2));
	dp[0][0] = 1;
	for (ll where = 0; where < len; where++) {

		// cout << k[where] << endl;
		// for (ll i = 0; i < d; i++) {
		// 	cout << dp[i][0] << "," << dp[i][1] << " ";
		// }
		// cout << endl;
		vvl temp(d, vl(2));
		for (ll sum = 0; sum < d; sum++) {
			for (ll j : {0, 1}) {
				for (ll digit = 0; digit < 10; digit++) {
					if (digit > k[where] - '0' && !j) {
						break;
					}
					add_self(temp[(sum + digit) % d][j || (digit < k[where] - '0')], dp[sum][j]);
				}
			}
		}
		dp = temp;

		// for (ll i = 0; i < d; i++) {
		// 	cout << dp[i][0] << "," << dp[i][1] << " ";
		// }
		// cout << endl << endl;

	}

	ll ans = (dp[0][0] + dp[0][1]) % MOD;
	ans--;
	if (ans == -1) ans = MOD - 1;
	cout << ans; brk;

}