#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int N, M, W, T;
const int MAX = 8;
const int MAXW = 11111;
string S[MAX];
int V[MAX], P[MAX];
int X[MAX], Y[MAX], L[MAX];
int R[MAX][MAX], Q[MAX][MAX];
ll dp[MAXW];

const int INF = 1e9;
int minTime[1 << MAX];
namespace TSP {
	int dp[1 << MAX][MAX];
	int dfs(int state, int now, int all) {
		int& ret = dp[state][now];
		if (ret >= 0) return ret;
		ret = INF;
		if (state == all) return ret = abs(X[now]) + abs(Y[now]);
		for (int i = 0; i < N; i++) if ((all >> i) & 1) {
			if ((state >> i) & 1) continue;
			ret = min(ret, abs(X[now] - X[i]) + abs(Y[now] - Y[i]) + dfs(state | (1 << i), i, all));
		}
		return ret;
	}
}

int best[1 << MAX];
namespace Item {
	ll dp[MAXW];
	ll calc(int state, int M, int W, vi costs) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < M; i++) {
			if ((state>>i)&1) {
				for (int j = 0; j+V[i] <= W; j++) {
					dp[j+V[i]] = max(dp[j+V[i]], dp[j] + P[i]-costs[i]);
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i <= W; i++)
			ans = max(ans, dp[i]);
		return ans;
	}
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	cin >> N >> M >> W >> T;
	for (int i = 0; i < M; i++) {
		cin >> S[i] >> V[i] >> P[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> L[i] >> X[i] >> Y[i];
		for (int j = 0; j < L[i]; j++) {
			string s;
			cin >> s >> Q[i][j];
			for (int k = 0; k < M; k++) {
				if (S[k] == s) R[i][j] = k;
			}
		}
	}
	// ??????????????????????¨???????????????????????????????????°?????????????????±???????
	for (int s = 1; s < 1 << N; s++) {
		memset(TSP::dp, -1, sizeof(TSP::dp));
		int mini = INF;
		for (int i = 0; i < N; i++) if ((s >> i) & 1) {
			mini = min(mini, abs(X[i]) + abs(Y[i]) + TSP::dfs(1 << i, i, s));
		}
		minTime[s] = mini;
	}
	map<int, ll> mp;
	for (int s = 1; s < 1<<N; s++) {
		if (minTime[s] > T) continue;
		// ?????????????¨?????????§??????????????¢??????????????????
		int item = 0;
		vector<int> unko(M, INF);
		for (int j = 0; j < N; j++) if ((s>>j)&1) {
			for (int k = 0; k < L[j]; k++) {
				int l = R[j][k];
				item |= 1<<l;
				unko[l] = min(unko[l], Q[j][k]);
			}
		}
		ll tmp = Item::calc(item, M, W, unko);
		//cout << s << " " << tmp << endl;
		mp[minTime[s]] = max(mp[minTime[s]], tmp);
	}
	// dp
	for (int i = 0; i <= T; i++) {
		for (auto p : mp) {
			if (i+p.first <= T) {
				dp[i+p.first] = max(dp[i+p.first], dp[i] + p.second);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= T; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
    return 0;
}