#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<iomanip>
#include<functional>
using namespace std;

int INF = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int n, m;

vector<bool> visit(20, false);
vector<vector<bool>> g(20, vector<bool>(20, false));

int dfs(int x) {
	visit[x] = true;

	bool allvisit = true;

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) allvisit = false;
	}

	if (allvisit) return 1;

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (g[x][i] == true && visit[i] == false) {
			ans += dfs(i);
			visit[i] = false;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;
	}
	cout << dfs(1) << endl;
}