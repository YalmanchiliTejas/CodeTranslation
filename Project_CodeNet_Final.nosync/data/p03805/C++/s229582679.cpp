#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

vector<int> G[10];
int dp[10][1<<10];
int N, M;

int dfs(int v, int state) {
	int& ret = dp[v][state];
	if (ret >= 0) return ret;
	if (state == (1<<N)-1) return ret = 1;
	ret = 0;
	for (int el : G[v]) {
		if ((state>>el)&1) continue;
		ret += dfs(el, state|(1<<el));
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1) << endl;
	return 0;
}
