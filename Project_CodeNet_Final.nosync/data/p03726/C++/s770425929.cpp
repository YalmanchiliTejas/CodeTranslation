#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int n,col[MAXN],Ok;
vector<int>P[MAXN];
void dfs(int u,int fa){
	int cnt[2]={0,0},p;
	int size=P[u].size();
	for(int i=0;i<size;i++){
		int v=P[u][i];
		if(v==fa)continue;
		dfs(v,u);
		cnt[col[v]]++;
	}
	if(u==1&&cnt[1]==size)Ok=1;
	if(cnt[0]>=2)Ok=1;
	if(cnt[0])col[u]=1;
	else col[u]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		P[u].push_back(v);
		P[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(P[i].size()>1){
			dfs(1,0);
			break;
		}
	if(Ok)printf("First\n");
	else printf("Second\n");
}
/*
6
1 2
2 3
3 4
4 5
5 6

7
1 2
2 3
3 4
4 5
5 6
6 7
*/