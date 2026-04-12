#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 100000
int N,Root;
vector<int> G[MAXN+5];

int dfs(int u,int fa){//0黑 1百 -1必胜
	if(u!=Root&&G[u].size()==1)
		return 0;
	int cnt=0;
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i];
		if(v!=fa){
			int tmp=dfs(v,u);
			if(tmp==-1)
				return -1;
			cnt+=tmp==0;
		}
	}
	if(cnt>=2)
		return -1;
	if(u==Root)
		return cnt!=1;
	return cnt==1;
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=N;i++){
		if(G[i].size()==1){
			Root=i;
			break;
		}
	}
	puts(dfs(Root,-1)?"First":"Second");
    return 0;
}
