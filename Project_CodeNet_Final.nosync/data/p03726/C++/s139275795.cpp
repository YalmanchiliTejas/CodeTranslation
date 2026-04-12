#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int n,q;
int f[100001],dep[100001],d[100001],p[100001];
bool cmp(int i,int j){return dep[i]>dep[j];}

int h[100001],nxt[200001],to[200001],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int v[100001];

void DFS(int u,int fa){
	f[u]=fa; dep[u]=dep[fa]+1; ++d[fa];
	for(int i=h[u];i;i=nxt[i]) if(to[i]!=fa) DFS(to[i],u);
}

int main(){
	int x,y;
	scanf("%d",&n);
	F(i,2,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(1,0);
	F(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	F(I,1,n){
		int i=p[I];
		if(v[i]) continue;
		if(i==1) {puts("First"); return 0;}
		v[i]=1;
		if(--d[f[i]]) {puts("First"); return 0;}
		else v[f[i]]=1, --d[f[f[i]]];
	} puts("Second");
	return 0;
}