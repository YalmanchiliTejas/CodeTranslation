#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
const ll MOD = 1000000007;

ll sc[203][203];
ll dp[400][200][200];
map<pair<ll, ll>, ll> bef, aft;

void chmax(ll& x, ll y) {
	x = max(x, y);
}

int main() {
	for (ll i = 0;i < 203;i++)for (ll j = 0;j < 203;j++)sc[i][j] = INT64_MIN / 5;
	ll H, W;
	cin >> H >> W;
	for (ll i = 0;i < H;i++) {
		for (ll j = 0;j < W;j++) {
			cin >> sc[i][j];
		}
	}

	dp[0][0][0] = sc[0][0];

	for (int t = 0;t < H + W;t++) {
		for (int e8 = 0;e8 <= t;e8++) {
			if (e8 >= H)continue;
			if (t - e8 >= W)continue;
			for (int sq = 0;sq <= t;sq++) {
			if (sq >= H)continue;
			if (t - sq >= W)continue;
				if (e8 != sq) {
					chmax(dp[t + 1][e8][sq], dp[t][e8][sq] + sc[e8][t - e8 + 1] + sc[sq][t - sq + 1]);
					chmax(dp[t + 1][e8 + 1][sq + 1], dp[t][e8][sq] + sc[e8 + 1][t - e8] + sc[sq + 1][t - sq]);
				}
				else {
					chmax(dp[t + 1][e8][sq], dp[t][e8][sq] + sc[e8][t - e8 + 1]);
					chmax(dp[t + 1][e8 + 1][sq + 1], dp[t][e8][sq] + sc[e8 + 1][t - e8]);
				}

				if (e8 + 1 != sq) {
					chmax(dp[t + 1][e8 + 1][sq], dp[t][e8][sq] + sc[e8 + 1][t - e8] + sc[sq][t - sq + 1]);
				}
				else {
					chmax(dp[t + 1][e8 + 1][sq], dp[t][e8][sq] + sc[e8 + 1][t - e8]);
				}

				if (sq + 1 != e8) {
					chmax(dp[t + 1][e8][sq + 1], dp[t][e8][sq] + sc[e8][t - e8 + 1] + sc[sq + 1][t - sq]);
				}
				else {
					chmax(dp[t + 1][e8][sq + 1], dp[t][e8][sq] + sc[e8][t - e8 + 1]);
				}
			}
		}
	}
	cout << dp[H + W - 2][H - 1][H - 1] << endl;
}