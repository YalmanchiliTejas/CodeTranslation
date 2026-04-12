#include<cstdio>
struct edge{
	int to,nx;
}e[5000001];
int h[100005],p;
int n,ok=0;

void ae(int fr,int to){
	e[++p]=(edge){to,h[fr]};h[fr]=p;
}
int dfs(int u,int fa){
	int ret=0;
	for(int i=h[u];i;i=e[i].nx){
		if(e[i].to!=fa) ret+=dfs(e[i].to,u);
		if(ok==1) return 0;
	}
	if(ret>=2){
		puts("First");
		ok=1;
		return 0;
	}
	else if(ret) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ae(x,y);ae(y,x);
	}
	int ans=dfs(1,-1);
	if(!ok) if(ans) puts("First");
	else puts("Second");
	return 0;
}