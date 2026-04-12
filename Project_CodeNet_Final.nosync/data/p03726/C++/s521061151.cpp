#include<bits/stdc++.h>
#define N 100009
using namespace std;

int n,tot,fa[N],fst[N],pnt[N<<1],nxt[N<<1]; bool tg[N];
void gg(){
	puts("First"); exit(0);
}
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x){
	int i,y;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; dfs(y);
			if (tg[x]&&tg[y]) gg();
			tg[x]|=tg[y];
		}
	}
	tg[x]^=1;
	if (x==1 && tg[x]) gg();
}
int main(){
	scanf("%d",&n);
	int i,x,y;
	for (i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	puts("Second");
	return 0;
}
