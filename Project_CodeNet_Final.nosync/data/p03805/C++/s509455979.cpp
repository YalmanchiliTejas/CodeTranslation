#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;


int ans;

struct edge {
	int num;
	std::vector<int> fri;
	bool visit;
};


void dfs(std::vector<edge> v, int x){
	v[x].visit = false;
	bool flag = true;
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].visit) {
			flag = false;
			break;
		}
	}
	if (flag) {
		ans++;
		return ;
	}
	for (size_t i = 0; i < v[x].fri.size(); i++) {
		if (v[v[x].fri[i]].visit) {
			dfs(v,v[x].fri[i]);
		}
	}
}

int main(int argc, char const *argv[]) {
	int n,m;
	std::cin >> n >> m;
	std::vector<edge> v;
	for (size_t i = 0; i < n; i++) {
		v.push_back({i,{},true});
	}
	for (size_t i = 0; i < m; i++) {
		int a,b;
		std::cin >> a >> b;
		a--;
		b--;
		v[a].fri.push_back(b);
		v[b].fri.push_back(a);
	}
	ans = 0;
	dfs(v,0);
	std::cout << ans << '\n';
	return 0;
}
