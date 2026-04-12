#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll dp[101][4][2];

void solve_abc154() {
	string s;
	ll n, k;
	ll ans = 0;

	cin >> s >> k;

	n = s.size();

	dp[0][0][0] = 1;
	rep(i, n) {
		ll nd = s[i] - '0';
		rep(j, 4) {
			rep(p, 2) {
				rep(d, 10) {
					ll ni = i + 1;
					ll nj = j;
					ll np = p;

					if (d != 0) {
						nj++;
					}

					if (nj > k) {
						continue;
					}

					if (p == 0) {
						if (d > nd) {
							continue;
						}
						else if (d < nd) {
							np = 1;
						}
					}
					dp[ni][nj][np] += dp[i][j][p];
				}
			}
		}
	}

	ans = dp[n][k][0] + dp[n][k][1];

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc154();

	return 0;
}