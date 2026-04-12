//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=15;
char mp[N][N];int vis[N][N],n,m;
bool dfs(int x,int y){
	vis[x][y]=1;
	if(x==n&&y==m)return true;
	R int c=0;
	if(x<n&&mp[x+1][y]=='#')++c;
	if(y<m&&mp[x][y+1]=='#')++c;
	if(c!=1)return false;
	if(x<n&&mp[x+1][y]=='#')return dfs(x+1,y);
	if(y<m&&mp[x][y+1]=='#')return dfs(x,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	fp(i,1,n)scanf("%s",mp[i]+1);
	if(mp[1][1]!='#'||mp[n][m]!='#')return puts("Impossible"),0;
	if(!dfs(1,1))return puts("Impossible"),0;
	fp(i,1,n)fp(j,1,m)if((mp[i][j]=='#')!=vis[i][j])return puts("Impossible"),0;
	return puts("Possible"),0;
}