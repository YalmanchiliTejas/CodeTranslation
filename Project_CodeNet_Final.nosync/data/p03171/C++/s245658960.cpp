#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll a[3000];
ll memo[2][3000][3000];
ll solve(int turn, int l, int r) {
	if (l == r) {
		if (turn) return a[l];
		else return -a[l];
	}
	if (memo[turn][l][r] != 1LL << 60) return memo[turn][l][r];
	if (turn) {
		return memo[turn][l][r] = max(a[l] + solve(!turn, l + 1, r), a[r] + solve(!turn, l, r - 1));
	}
	else {
		return memo[turn][l][r] = min(-a[l] + solve(!turn, l + 1, r), -a[r] + solve(!turn, l, r - 1));
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	fill((ll*)memo, (ll*)(memo + 2), 1LL << 60);
	cout << solve(1, 0, N - 1) << endl;
}