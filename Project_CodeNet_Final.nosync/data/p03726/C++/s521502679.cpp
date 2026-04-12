#include <stdio.h>
#include <string.h>
#define N 100010
int n;char flag=0,mat[N];
int ne=0,h[N];struct edge{int to,x;}e[N<<1];
inline void ins(int s,int t) {
	e[++ne].to=t;e[ne].x=h[s];h[s]=ne;
}
void dfs(int s,int fa) {
	mat[s]=0;
	for(int i=h[s],v;i;i=e[i].x) {
		v=e[i].to;
		if(v!=fa) {
			dfs(v,s);
			if(!mat[v]) {
				if(!mat[s]) mat[s]=1;
				else flag=1;
			}
		}
	}
}
int main() {
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;++i) {
		scanf("%d%d",&a,&b);
		ins(a,b);ins(b,a);
	}
	dfs(1,0);
	puts(flag||!mat[1]?"First":"Second");
	return 0;
}