#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MOD = 998244353;
int N, S;
vector<int> v;

int cache[3001][3001];

//f(pos, j)=k 인 pos <= j < N의 개수
int solve(int pos, int k) {
	if (k == 0) return N - pos + 1;
	if (pos == N) return 0;

	int& ret = cache[pos][k];
	if (ret != -1) return ret;

	ret = solve(pos + 1, k) % MOD;
	if (k - v[pos] >= 0) ret = (ret + solve(pos + 1, k - v[pos])) % MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> S;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int ans = 0;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
		ans = (ans + solve(i, S)) % MOD;

	cout << ans << "\n";
	return 0;
}
