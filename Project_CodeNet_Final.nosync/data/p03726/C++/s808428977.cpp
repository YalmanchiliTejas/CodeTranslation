#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define R register
inline int read(){
	R int x; R bool f; R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c^'0'; (c=getchar())>='0'&&c<='9'; x=(x<<1)+(x<<3)+(c^'0'));
	return f?-x:x;
}
#define MN 100005
int n,to[MN<<1],nxt[MN<<1],col[MN],en,hd[MN];
inline void ins(int u,int v){to[++en]=v;nxt[en]=hd[u];hd[u]=en;}
inline void insw(int x,int y){ins(x,y);ins(y,x);}
bool dfs(int u,int f=0){
	R int cnt=0;
	for (R int i=hd[u]; i; i=nxt[i])
		if (to[i]!=f){
			if (dfs(to[i],u)) ++cnt;
			if (cnt>>1) puts("First"),exit(0); 
		}col[u]=cnt^1;return col[u];
}
int main(){
	n=read();for (R int i=1; i<n; ++i)
		insw(read(),read());
	dfs(1);if (col[1]) puts("First");
	else puts("Second");return 0;
}