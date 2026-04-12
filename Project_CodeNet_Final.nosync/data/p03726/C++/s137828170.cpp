#include<bits/stdc++.h>
const int N=100005;
using namespace std;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
int n,f[N][2];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	f[x][1]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			f[x][0]=(f[x][0]&f[e[i].to][0])|
					(f[x][1]&f[e[i].to][1]);
			f[x][1]&=f[e[i].to][0];
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	puts(f[1][0]?"Second":"First");
}