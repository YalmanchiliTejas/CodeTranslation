#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> e[N];
queue<int> Q;
int n,deg[N];
bool del[N],white[N];
void erase(int x){
	del[x]=1;
	for (int i=0;i<e[x].size();i++){
		int v=e[x][i];
		if (del[v]) continue;
		deg[v]--;
		if (deg[v]==0) puts("First"),exit(0);
		if (deg[v]==1) Q.push(v);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;deg[v]++;
	}
	for (int i=1;i<=n;i++)
		if (deg[i]==1) Q.push(i);
	while (!Q.empty()){
		int v=Q.front();Q.pop();
		del[v]=1;
		for (int i=0;i<e[v].size();i++){
			int u=e[v][i];
			if (del[u]) continue;
			erase(u);
		}
	}
	puts("Second");
	return 0;
}