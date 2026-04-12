#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> H(N), W(N);
	rep(i, 0, N)cin >> H[i] >> W[i];
	int C[4][4];
	int goals[3] = {};
	rep(i, 0, 4)rep(j, 0, 4) {
		char c; cin >> c;
		if (c == 'R')
			C[i][j] = 0;
		else if (c == 'G')
			C[i][j] = 1;
		else
			C[i][j] = 2;
		goals[C[i][j]] |= 1 << (i * 4 + j);
	}
	vector<int> stamps;
	auto inrange = [&](int i, int j) {return 0 <= i && i < 4 && 0 <= j && j < 4; };
	rep(s, 0, N) {
		rep(i, -3, 4)rep(j, -3, 4) {
			int mask = 0;
			rep(ci, i, i + H[s])rep(cj, j, j + W[s]) {
				if (!inrange(ci, cj))continue;
				mask |= (1 << (ci * 4 + cj));
			}
			stamps.push_back(mask);
		}
	}
	queue<int> q;
	q.push(0);
	const int INF = 100;
	vector<int> dp(1 << 16, INF);
	dp[0] = 0;
	int fin = (1 << 16) - 1;
	while (q.size()) {
		int now = q.front(); q.pop();
		rep(c, 0, 3) {
			for (auto stamp : stamps) {
				int next = (~stamp & now) | (goals[c] & stamp);
				if (dp[next] != INF)continue;
				dp[next] = dp[now] + 1;
				if (next == fin) {
					cout << dp[fin] << endl;
					return 0;
				}
				q.push(next);
			}
		}
	}

	return 0;
}
