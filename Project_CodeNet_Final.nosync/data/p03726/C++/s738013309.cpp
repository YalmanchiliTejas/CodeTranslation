#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set> 
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define db double
#define inf 200001
#define INF (int)1e9
#define mod (int)(1e9+7)
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;
int n;

struct edge{
	int y,nxt;
	edge(){}
	edge(int yy,int nn){
		y=yy,nxt=nn;
	}
}e[inf*2];
int head[inf],ecnt;

void addedge(int x,int y){
	ecnt++;
	e[ecnt]=edge(y,head[x]);
	head[x]=ecnt;
	return;
}

int siz[inf],fa[inf],far[inf],cnts[inf];

void dfs1(int u,int last){
	fa[u]=last;
	siz[u]=1;
	int mx=0;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if (v==last){
			continue;
		}
		cnts[u]++;
		dfs1(v,u);
		mx=max(mx,far[v]+1);
		siz[u]+=siz[v];
	}
	if (cnts[u]==1){
		far[u]=mx;
	}
	return;
}

void dfs2(int u){
	int cnt=0;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if (v==fa[u]){
			continue;
		}
		dfs2(v);
		if (siz[v]>0){
			cnt++;
		}
	}
	if (cnt>=2){
		puts("First");
		exit(0);
	}
	if (u==1 && cnt==0){
		puts("First");
		exit(0);
	}
	if (u==1 && cnt==1){
		puts("Second");
		exit(0);
	}
	if (cnt==0){
		return;
	}
	if (cnt==1){
		siz[u]=-1;
	}
	return;
}

int main(){
	rd(n)
	if (n==2){
		puts("Second");
		return 0;
	}
	int x,y;
	for (int i=1;i<n;i++){
		rd(x) rd(y)
		addedge(x,y);
		addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1);
	return 0;
}