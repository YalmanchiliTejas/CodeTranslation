#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

set<int> g[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].insert(b);
		g[b].insert(a);
	}
	queue<int> q;
	for (int i=1;i<=n;i++){
		q.push(i);
	}
	int nn=n;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		if (g[x].size()==2){
			for (int nx:g[x]){
				if (g[nx].size()==1){
					x=nx;
					break;
				}
			}
		}
		if (g[x].size()!=1) continue;
		int nx=*g[x].begin();
		if (g[nx].size()!=2) continue;
		for (int nnx:g[nx]){
			g[nnx].erase(nx);
			q.push(nnx);
		}
		g[nx].clear();
		g[x].clear();
		nn-=2;
	}
	for (int i=1;i<=n;i++){
		if (g[i].size()>=3){
			cout<<"First"<<endl;
			return 0;
		}
	}
	if (nn%2==1){
		cout<<"First"<<endl;
	}
	else{
		cout<<"Second"<<endl;
	}
}