#include <cstdio>
#include <vector>
#include <cstring>
#define maxn (ll)1e5+10
using namespace std;
typedef long long ll;
int n,fa[maxn];
bool color[maxn];
vector<int> map[maxn];
int du[maxn];
void dfs(int u,int p) {
	fa[u]=p;
	bool t=false;
	for (int i=0;i<map[u].size();i++) {
		int v=map[u][i];
		if (v==p)
			continue;
		t=true;
		dfs(v,u);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		map[a].push_back(b);
		map[b].push_back(a);
		du[a]++;
		du[b]++;
	}
	dfs(1,0);
	memset(color,0,sizeof(color));
	color[0]=1;
	for (int i=1;i<=n;i++) {
		bool t=false;
		for (int j=1;j<=n;j++)
			if (!color[j]&&!color[fa[j]]&&du[j]==1) {
				color[j]=1;
				color[fa[j]]=1;
				du[j]=0;
				du[fa[j]]=0;
				for (int k=0;k<map[fa[j]].size();k++)
					du[map[fa[j]][k]]--;
				t=true;
			}
		if (!t)
			break;
	}
	/*
	for (int i=1;i<=n;i++)
		printf("%d %d\n",i,color[i]);
	*/
	bool ans=false;
	for (int i=1;i<=n;i++)
		if (!color[i]) {
			ans=true;
			break;
		}
	if (ans)
		printf("First\n");
	else printf("Second\n");
	return 0;
}