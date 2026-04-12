#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, A[200005];
map<pair<int, int>, int> mem;

int dp(int n, int k) {
	if (k == 0) return 0;
	if (mem.find(mp(n, k)) != mem.end()) return mem[mp(n, k)];
	if ((N - n + 2) / 2 < k) return -1e17;
	if (n >= N + 1) return (k == 0 ? 0 : -1e17);
	return mem[mp(n, k)] = max(dp(n + 2, k - 1) + A[n], dp(n + 1, k));
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << dp(1, N / 2) << '\n';
}
