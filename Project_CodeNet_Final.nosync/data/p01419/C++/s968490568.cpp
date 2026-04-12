#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 2600
#define maxe 1100000
#define inf 99999999

int R,C,m;
int save[maxn];
char str[60][60];
int tit[maxn];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int getid(int x,int y){
	return x*C+y;
}
int net[maxn],size;
void init(){
	size=0;
	memset(net,-1,sizeof(net));
}
struct EDGE{
	int v,next;
}edge[maxe];
void add(int u,int v){
	edge[size].v=v;
	edge[size].next=net[u];
	net[u]=size++;
}

int cc,s,t;
vector<int> path[maxn];//蛟堤捩譚・逧?
bool dfs(int u,int fa){
	if(u==t) return true;
	for(int i=net[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue;
		if(dfs(v,u)){
			path[cc].push_back(v);
			return true;
		}
	}
	return false;
}
int cost[60][60];
int kai[60][60],guan[60][60];
int main(){
	
	while(scanf("%d%d%d",&R,&C,&m)!=EOF){
		memset(tit,-1,sizeof(tit));
		for(int i=0;i<R;i++){
			scanf("%s",str[i]);
		}
		init();
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(str[i][j]=='#') continue;
				for(int k=0;k<4;k++){
					int x=i+dir[k][0];
					int y=j+dir[k][1];
					if(x<0 || x>=R || y<0 || y>=C) continue;
					if(str[x][y]=='#') continue;
					add(getid(i,j), getid(x,y));
				//	add(getid(x,y), getid(i,j));
				}
			}
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				scanf("%d",&cost[i][j]);
			}
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				scanf("%d",&kai[i][j]);
			}
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				scanf("%d",&guan[i][j]);
			}
		}
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			save[i]=getid(x,y);
		}
		cc=0;
		for(int i = 0 ; i < m ; i ++)path[i].clear();
		for(int i=1;i<m;i++){
			s=save[i]; t=save[i+1];
			cc++;
			dfs(s,-1);
			path[cc].push_back(s);
		}
		
		int tt = 0 ;
		int ttt = 1;
		for(int i = 1 ; i < m ; i ++) {
			int cccc = 1;
			if(i != 1)cccc ++;
			for(int j = (int)path[i].size() - cccc ; j >= 0 ; j --) {
				int idx = path[i][j];
				int rr = idx / C;
				int cc = idx % C;
				if(tit[idx] == -1) {
					tt += kai[rr][cc] + guan[rr][cc];
					tit[idx] = ttt;
				}
				else {
					tt += min(kai[rr][cc] + guan[rr][cc] , (ttt - tit[idx]) * cost[rr][cc]);
					tit[idx] = ttt;
				}
				ttt ++;
			}
		}
		printf("%d\n",tt);
	}
	return 0;
}