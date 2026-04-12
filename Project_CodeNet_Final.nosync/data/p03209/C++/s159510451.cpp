#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int len[52], pat[52];

int dfs(int N, int X) {
	if (N == 0) return X > 0;
	if (X >= len[N]) return pat[N];
	if (X == len[N] / 2 + 1) return pat[N - 1] + 1;
	if (X < len[N] / 2 + 1) return dfs(N - 1, X - 1);
	return dfs(N - 1, X - (len[N] / 2 + 1)) + pat[N - 1] + 1;
}

signed main() {
	len[0] = 1;
	pat[0] = 1;

	REP(i, 1, 50) {
		len[i] = 2 * len[i - 1] + 3;
		pat[i] = 2 * pat[i - 1] + 1;
	}

	int N, X;
	cin >> N >> X;

	cout << dfs(N, X) << endl;
}
