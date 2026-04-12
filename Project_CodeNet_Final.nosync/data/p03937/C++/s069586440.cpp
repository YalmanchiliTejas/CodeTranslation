#include<cstdio>
using namespace std;
const int maxn=20;
int n,m,cnt;
char mp[maxn][maxn];bool vis[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) if(mp[i][j]=='#') cnt++;
	if(cnt!=n+m-1){puts("Impossible");return 0;}
	vis[0][1]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	vis[i][j]=mp[i][j]=='#'&&(vis[i][j-1]||vis[i-1][j]);
	puts(vis[n][m]?"Possible":"Impossible");
	return 0;
}