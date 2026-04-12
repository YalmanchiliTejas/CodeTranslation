#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=1e5;

int N;
vector<int> G[Maxn+5];
void addedge(int u,int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

int DFS(int u,int fa) {
	int p=0;
	for(int i=0;i<(int)G[u].size();i++) {
		int v=G[u][i];
		if(v==fa)continue;
		p+=DFS(v,u);
	}
	if(p>=2)return p;
	else return p^1;
}

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&N);
	for(int i=1;i<N;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(u,v);
	}
	puts(DFS(1,-1)==0?"Second":"First");
	return 0;
}