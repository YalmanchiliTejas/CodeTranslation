#include <cstdio>
#include <cstring>
#define maxn 10
using namespace std;
int n,m,ans;
bool to[maxn][maxn],e[maxn];
int d[maxn];
void dfs(int a) {
	if (a>n) {
		for (int i=1;i<n;i++)
			if (!to[d[i]][d[i+1]])
				return;
		ans++;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!e[i]) {
			e[i]=1;
			d[a]=i;
			dfs(a+1);
			e[i]=0;
		}
}
int main() {
	scanf("%d %d",&n,&m);
	memset(to,0,sizeof(to));
	for (int i=1;i<=m;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		to[a][b]=1;
		to[b][a]=1;
	}
	memset(e,0,sizeof(e));
	ans=0;
	d[1]=1; e[1]=1;
	dfs(2);
	printf("%d\n",ans);
	return 0;
}