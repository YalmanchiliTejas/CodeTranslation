#include<cstdio>
char*str[2]={"Second","First"};
struct edge{int to;edge*next;}E[200010],*ne,*first[100010];
int Q[100010],deg[100010];
void link(int u,int v){*ne=(edge){v,first[u]};first[u]=ne++;deg[v]++;}
bool del[100010];
int solve(){
	int N;scanf("%d",&N);ne=E;
	for(int i=1;i<=N;i++)first[i]=0,deg[i]=del[i]=0;
	for(int i=1,u,v;i<N;i++)scanf("%d%d",&u,&v),link(u,v),link(v,u);
	int*h=Q,*t=Q;
	for(int i=1;i<=N;i++)if(deg[i]<2)*t++=i;
	for(;h<t;h++)if(!del[*h]){
		int x=-1;
		for(edge*e=first[*h];e&&x<0;e=e->next)
			if(!del[e->to])--deg[x=e->to];
		if(x<0)return 1;
		del[*h]=del[x]=1;
		for(edge*e=first[x];e;e=e->next)
			if(!del[e->to]&&--deg[e->to]==1)*t++=e->to;
	}
	return 0;
}
int main(){
	puts(str[solve()]);
}