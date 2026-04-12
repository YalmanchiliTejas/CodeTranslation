#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> G[100000];
int m[100000];

int flag = 0;

void dfs(int v, int p) {
	for(auto c : G[v]) {
		if(c == p) continue;
		dfs(c, v);
	}
	if(m[v] == 0) {
		m[v] = 1;
		if(p == -1 || m[p]) {
			flag = 1;
			return;
		}
		m[p] = 1;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0, -1);

	if(flag) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}

}