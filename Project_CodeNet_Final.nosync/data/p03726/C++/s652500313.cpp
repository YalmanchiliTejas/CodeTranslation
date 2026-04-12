#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
int n,tot,head[100010],to[200010],nxt[200010];
void add_edge(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	return;
}
int dfs(int u,int father){
	int ret=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v!=father)
			ret+=dfs(v,u);
		if(ret>=2){
			puts("First");
			exit(0);
		}
	}
	return ret^1;
}
int rd(){
	int x=0;
	char c;
	do c=getchar();
	while(!isdigit(c));
	do{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}while(isdigit(c));
	return x;
}
int main(){
	n=rd();
	for(int i=1;i<n;i++){
		int u=rd(),v=rd();
		add_edge(u,v);
		add_edge(v,u);
	}
	puts(dfs(1,0)?"First":"Second");
	return 0;
}