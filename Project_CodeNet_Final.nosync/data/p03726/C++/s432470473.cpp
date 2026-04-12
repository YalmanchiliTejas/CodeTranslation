#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
#define MAXN 200005
#define INF 0x3f3f3f3f
bool f[MAXN+5],pan;
vector<int> G[MAXN+5];
void DFS(int u,int fa){
	int cnt=0;
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i];
		if(v==fa) continue;
		DFS(v,u);
		if(f[v]==1)
			cnt++;
	}
	if(cnt>=2){
		puts("First");
		exit(0);
	}
	f[u]=cnt^1;
	return ;
}
int main(){
	int n=read();
	for(int i=2;i<=n;i++){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1,0);
	puts(f[1]?"First":"Second");
	return 0;
}//