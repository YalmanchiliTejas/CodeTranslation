#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],tot;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
int dfs(int x,int f) {
	int s=1;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=f)s+=dfs(to[i],x);
	if(s>2)puts("First"),exit(0);
	if(s==2)return 0;
	return 1;
}
int main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	puts(dfs(1,0)?"First":"Second");
	return 0;
}