#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
struct edge{
	int k,next;
}e[N<<1];
int n,home[N],cnt=-1,IN[N],s[N],top,fa[N],col[N];
void add(int x,int y){
	cnt++;
	e[cnt].k=y;
	e[cnt].next=home[x];
	home[x]=cnt;
}
void dfs(int k,int F){
	fa[k]=F;
	for(int i=home[k];~i;i=e[i].next) if(e[i].k!=F){
		dfs(e[i].k,k);
	}
}
bool solve(){
	int x,y;
	while(top){
		x=s[top];y=fa[x];
		if(col[x]){
			top--;continue;
		}
		if(col[y]) return 1;
		col[y]=1;
		IN[fa[y]]--;
		top--;
		if(IN[fa[y]]==1) s[++top]=fa[y];
	}
	return 0;
}
int main(){
	memset(home,-1,sizeof(home));
	scanf("%d",&n);
	if(n==2) return puts("Second"),0;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		IN[x]++;IN[y]++;
	}
	int S;
	for(int i=1;i<=n;i++)
		if(IN[i]==1) s[++top]=i;
		else S=i;
	dfs(S,0);
	if(solve()) puts("First");
	else puts("Second");
	return 0;
}