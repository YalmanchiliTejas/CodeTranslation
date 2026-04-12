#include <iostream>
#include <vector>
using namespace std;
int n, m, u, v, s, x[9];
vector<int> g[9];

void f(int p, int q) {
	if(q==n) {s++; return;}
	x[p] = 1;
	for(int i=0; i<g[p].size(); i++)
		if(!x[g[p][i]]) f(g[p][i], q+1);
	x[p] = 0;
}

int main() {
	cin>>n>>m;
	while(m--) {
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	f(1, 1);
	cout<<s;
	return 0;
}