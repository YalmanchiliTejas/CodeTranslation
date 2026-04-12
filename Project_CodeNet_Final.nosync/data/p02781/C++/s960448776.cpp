#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 1000000007;

string N;
ll ns;

ll free(ll pos, ll k) {
	if (k == 0)return 1;
	if (k == 1) {
		return (ns - pos) * 9;
	}
	if (k == 2) {
		return (ns - pos) * (ns - pos - 1) / 2 * 81;
	}
	if (k == 3) {
		return (ns - pos) * (ns - pos - 1) * (ns - pos - 2) / 6 * 729;
	}
}

ll dfs(ll pos, ll k) {
	if (k == 0)return 1;
	if (pos == ns)return 0;
	if (N[pos] == '0') {
		return dfs(pos + 1, k);
	}
	return free(pos + 1, k) + (N[pos] - 49) * free(pos + 1, k - 1) + dfs(pos + 1, k - 1);
}

int main() {
	cin >> N;
	ll K;
	cin >> K;
	ns = N.size();
	cout << dfs(0, K);
}