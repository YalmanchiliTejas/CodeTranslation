#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>

#define INF 1000000000000000000
using namespace std;
typedef long long ll;

bool used[8];
vector<int> e[8];
int ans = 0;
int cnt = 0;
int n, m;

void dfs(int v) {
	cnt++;
	if (cnt == n) {
		ans++;
		return;
	}
	used[v] = true;
	for (auto &&id : e[v]) {
		if (!used[id]) {
			dfs(id);
			used[id] = false;
			cnt--;
		}
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a - 1].push_back(b - 1);
		e[b - 1].push_back(a - 1);
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
