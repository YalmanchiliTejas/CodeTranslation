#include "bits/stdc++.h"

using namespace std;

#define int long long
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define INF (1 << 30)

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	if (K == 0) cout << N * N << endl;
	else {
		int res = 0;
		FOR(i, K + 1, N + 1) {
			res += (N / i) * (i - K) + max(0LL, N % i - K + 1);
		}
		cout << res << endl;
	}
	return 0;
}
