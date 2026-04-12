#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100000 + 50;
const int mod = 1e9 + 7;

vector<int> t[maxn];
int maxmatch;

bool dfs(int v, int par = -1){
	bool flag = 0;
	for (auto u : t[v]){
		if (u == par)
			continue;
		bool me = dfs(u, v);
		if (me == 1)
			continue;
		if (flag == 0){
			flag = 1;
			maxmatch += 2;
		}
	}
	return flag;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		v --, u --;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(0);
	if (maxmatch == n)
		cout << "Second\n";
	else
		cout << "First\n";
}
