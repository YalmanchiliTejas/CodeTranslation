#include <cstdio>

using namespace std;

const int N=1e5+10;

struct Edge{ int to,next; };

Edge way[N<<1];
int n,num[N],tot;
bool use[N];

void AddEdge(int a,int b) { way[++tot]=(Edge){b,num[a]}; num[a]=tot; }

void Init()
{
	scanf("%d",&n);
	int a,b;
	for (int i=2;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		AddEdge(a,b);
		AddEdge(b,a);
	}
}

void Dfs(int x,int fa)
{
	for (int i=num[x];i;i=way[i].next)
	{
		int v=way[i].to;
		if (v==fa) continue;
		Dfs(v,x);
	}
	if (!use[x] && fa && !use[fa])
	{
		use[x]=1;
		use[fa]=1;
	}
}

void Solve()
{
	Dfs(1,0);
	
	bool fl=1;
	for (int i=1;i<=n;++i)
		if (!use[i]) fl=0;
	if (fl) printf("Second\n");
	else printf("First\n");
}

int main()
{
	Init();
	Solve();
	return 0;
}