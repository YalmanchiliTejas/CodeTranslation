#include <iostream>
#include <vector>
using namespace std;
int n,m,u,v,s;
vector<int> a[9];
bool z[9];

void f(int p, int q, int r) {
	if(r==n) {s++; return;}
	for(int i=0; i<a[p].size(); i++) {
		if(!z[a[p][i]] && a[p][i]!=q) {
			z[a[p][i]] = 1;
			f(a[p][i], p, r+1);
			z[a[p][i]] = 0;
		}
	}
}

int main() {
	cin>>n>>m;
	while(m--) {
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	z[1] = 1;
	f(1,0,1);
	cout<<s;
	return 0;
}