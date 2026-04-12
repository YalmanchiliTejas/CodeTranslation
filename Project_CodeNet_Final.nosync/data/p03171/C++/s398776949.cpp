#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
vector<int> a;
vector<vector<vector<ll> > > memo;

ll solve(int n, int l, int r) { //n 行動するひと l左端 r右端
	if (memo[n][l][r] != -INF_LL)return memo[n][l][r];
	if (l == r) {
		if (n == 0)return a[l];
		else return -a[l];
	}
	else {
		if (n == 0) {
			memo[n][l][r] = max(solve(1, l + 1, r) + a[l], solve(1, l, r - 1) + a[r]);
		}
		else {
			memo[n][l][r] = min(solve(0, l + 1, r) - a[l], solve(0, l, r - 1) - a[r]);
		}
		return memo[n][l][r];
	}
}
int main() {
	int N;
	cin >> N;
	a = vector<int>(N);
	for (int i = 0; i < N; i++)cin >> a[i];
	memo = vector<vector<vector<ll> > >(2, vector<vector<ll> >(N, vector<ll>(N,-INF_LL)));
	cout << solve(0, 0, N - 1) << endl;
	return 0;
}