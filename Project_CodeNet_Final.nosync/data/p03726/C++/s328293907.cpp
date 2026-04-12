#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
using ii = pair<int,int>;
vector<int> e[maxn];
bool has = true;
int solve(int root, int par){
	if(e[root].size() == 1) return root;
	int bads = 0;
	for(int nxt : e[root]){
		if(nxt == par) continue;
		int val = solve(nxt, root);
		if(val != -1) bads++;
	}
	if(bads > 1) has = false;
	if(bads == 1) return -1;
	return root;
}
int main(){
	int n; cin >> n;
	if(n == 2){
		cout << "Second" << endl;
		return 0;
	}
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int rt = -1;
	for(int i = 1; i <= n; i++) if(e[i].size() > 1) rt = i;
	has &= -1 == solve(rt, 0);
	if(!has) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
