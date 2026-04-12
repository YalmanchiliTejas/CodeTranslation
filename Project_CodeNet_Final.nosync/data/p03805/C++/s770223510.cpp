#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define print(x) cout<<(x)<<endl
#define INF10 1001001001 
#define INF5 100000
#define EPS 1e-10


int N, M;
vector<vector<int>> g;

int ans;

void dfs(int current, set<int>seen) {
	seen.insert(current);
	if (seen.size() == N) {
		ans++;
		seen.erase(current);
		return;
	}
	else {
		for (int i = 0; i < g[current].size(); i++) {
			int nx = g[current][i];
			if (seen.count(nx) == 0) {
				dfs(nx, seen);
			}
		}
		seen.erase(current);
		return;
	}
}

int main() {
	cin >> N >> M;
	g.assign(N, vector<int>());
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, set<int>());

	cout << ans << endl;






	return 0;
}
