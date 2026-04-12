#include <bits/stdc++.h>

#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define pii pair<int, int>
#define mp make_pair
#define f first
#define ll long long
#define ld long double
#define s second
#define vec vector<int>

using namespace std;

const int N = (int) 1e3 + 10;
const int M = (int) 2e6 + 10;
const int K = (int) 20;
const int INF = (int) 1e9 + 7;
const int mod = (int) 998244353;
const ld EPS = (ld) 1e-9;
const ll LINF = (ll) 1e18;
int n;
vec all;
int h[N];

int mult(int x, int y) {
	return 1ll * x * y % INF;
}

void add(int &x, int y) {
	x += y;
	if (x >= INF)
		x -= INF;
	if (x < 0) 
		x += INF;
}

int sum(int x, int y) {
	add(x, y);
	return x;
}

int bp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y % 2) 
			ans = mult(ans, x);
		x = mult(x, x);
		y /= 2;
	}
	return ans;
}

int f(int l, int r) {
	// 2^l + 2^(l+1) + ... + 2^r
	int pref = sum(bp(2, r + 1), -1);
	add(pref, -sum(bp(2, l), -1));
	return pref;
}

int dp[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef sony
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	srand(time(0));
	cin >> n;
	bool try_it = true;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (try_it) {
			all.pb(h[i]);
			if (h[i] > 1)
				all.pb(h[i] - 1);
		}
	}
	all.pb(1);
	if (!try_it) {
		for (int i = 1; i <= 100; i++) {
			all.pb(i);
		}
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 0; i < sz(all); i++) {
		if (all[i] < h[1]) { 
			add(dp[1][i], f(h[1] - all[i + 1] + 1, h[1] - all[i]));

			/*
			for (int pos = all[i]; pos < all[i + 1]; pos++) {
				add(dp[1][i], bp(2, h[1] - pos)); 
			}
			*/
		}
	}
	dp[1][sz(all)] = 2; // no same
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < sz(all); j++) {
			if (all[j] >= h[i]) { 
				// 010100
				// 10101
				add(dp[i][sz(all)], mult(2, dp[i - 1][j]));
			} else {
				// all[j] < h[i]

				// 011000
				// abcde 
				if (h[i] <= h[i - 1]) {
					add(dp[i][j], dp[i - 1][j]);
				}
				// 011000
				// 100111abc
				if (h[i] > h[i - 1]) {
					add(dp[i][j], mult(bp(2, h[i] - h[i - 1]), dp[i - 1][j]));
				}
			}
		}
		if (h[i] <= h[i - 1]) {
			// 01010101
			// abcde
			add(dp[i][sz(all)], mult(2, dp[i - 1][sz(all)]));
		}
		if (h[i] > h[i - 1]) {	
			// 01010101
			// abcdefghijk
			// no same 
			add(dp[i][sz(all)], mult(2, dp[i - 1][sz(all)]));

			// same but >= h[i - 1]
			// 010101
			// 1010100

			for (int j = 0; j < sz(all); j++) {
				if (all[j] < h[i] && all[j] >= h[i - 1]) {
					add(dp[i][j], mult(f(h[i] - all[j + 1] + 1, h[i] - all[j]), dp[i - 1][sz(all)]));
					/*
					for (int pos = all[j]; pos < all[j + 1]; pos++) {
						add(dp[i][j], mult(bp(2, h[i] - pos), dp[i - 1][sz(all)]));
					}
					*/
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= sz(all); j++) {
		add(ans, dp[n][j]);
	}
	cout << ans;
	return 0;	
}