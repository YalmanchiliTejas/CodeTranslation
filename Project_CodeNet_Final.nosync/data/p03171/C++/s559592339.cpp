#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double EPS = 1e-6;
const int MAX_N = 3e3 + 5;

int N;
ll seq[MAX_N];
ll memo[MAX_N][MAX_N][2];

ll dp(int l, int r, int turn) {
	if (l == r) return turn == 0 ? seq[r] : -seq[r];
	if (memo[l][r][turn] != -1) return memo[l][r][turn];
	if (turn == 0) return memo[l][r][turn] = max(dp(l + 1, r, 1) + seq[l], dp(l, r - 1, 1) + seq[r]);
	else return memo[l][r][turn] = min(dp(l + 1, r, 0) - seq[l], dp(l, r - 1, 0) - seq[r]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}

	memset(memo, -1, sizeof memo);

	cout << dp(0, N - 1, 0) << '\n';

	return 0;
}