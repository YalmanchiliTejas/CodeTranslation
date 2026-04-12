#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>v(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i];
		v[i]--;
	}
	vector<vector<int>>edge(N, vector<int>(K));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> edge[i][j];
			edge[i][j]--;
		}
	}
	vector<int>dp(1 << M, MOD);
	dp[(1 << M) - 1] = 0;
	set<pair<int, int>>s;
	s.insert({ 0,(1 << M) - 1 });
	while(!s.empty()){
		vector<int>p(M);
		auto c = *s.begin();
		int cn = c.second;
		int cc = c.first;
		//cout << cn << " " << cc << endl;
		s.erase(*s.begin());
		if (dp[cn] < cc)continue;
		for (int j = 0; j < M; j++) {
			if (cn >> j & 1) {
				p[j] = v[j];
			}
			else {
				p[j] = -1;
			}
		}
		for (int j = 0; j < K; j++) {
			auto box = p;
			for (int k = 0; k < M; k++) {
				if (box[k] == -1)continue;
				box[k] = edge[box[k]][j];
			}
			int nx = 0;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (box[k] == v[l]) {
						nx |= 1 << l;
					}
				}
			}
			if (dp[cn] + 1 < dp[nx]) {
				dp[nx] = dp[cn] + 1;
				s.insert({ dp[nx],nx });
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
}
