#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;
const int MAX=100005;

struct UFS
{
	int fa[MAX];
	
	UFS()
	{
		for(int i=0;i<MAX;i++)
			fa[i]=i;
	}
	
	inline int Find(int a)
	{
		if(fa[a]!=a)
			return fa[a]=Find(fa[a]);
		return a;
	}
	
	inline void Union(int a,int b)//Add Edge a->b
	{
		a=Find(a);
		b=Find(b);
		if(a!=b)
			fa[a]=b;
	}
}rowl,rowr,coll,colr;

int n;
int x[MAX],y[MAX];

vector<pii> row,col;
int xp[MAX],yp[MAX];

priority_queue<pii> Q;
bool vis[MAX];

inline void Update(int cur)
{
	int p;
	int left,right;
	
	p=xp[cur];
	left=rowl.Find(p-1),right=rowr.Find(p+1);
	if(left>=1)
	{
//		printf("Case 1:%d %d\n",p,left);
		rowl.Union(p,left);
		Q.push(mp(-row[p].first+row[left].first,row[left].second));
	}
	if(right<=n)
	{
//		printf("Case 2: %d %d\n",p,right);
		rowr.Union(p,right);
		Q.push(mp(-row[right].first+row[p].first,row[right].second));
	}
	
	p=yp[cur];
	left=coll.Find(p-1),right=colr.Find(p+1);
	if(left>=1)
	{
//		printf("Case 3: %d %d\n",p,left);
		coll.Union(p,left);
		Q.push(mp(-col[p].first+col[left].first,col[left].second));
	}
	if(right<=n)
	{
//		printf("Case 4: %d %d\n",p,right);
		colr.Union(p,right);
		Q.push(mp(-col[right].first+col[p].first,col[right].second));
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		row.pb(mp(x[i],i));
		col.pb(mp(y[i],i));
	}
	
	row.pb(mp(-1,0));
	col.pb(mp(-1,0));
	sort(row.begin(),row.end());
	sort(col.begin(),col.end());
	for(int i=1;i<=n;i++)
	{
		xp[row[i].second]=i;
		yp[col[i].second]=i;
	}
	
/*	for(int i=1;i<=n;i++)
		printf("%d(%d) ",row[i].first,row[i].second);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d(%d) ",col[i].first,col[i].second);
	printf("\n");*/
	
	long long ans=0;
	Q.push(mp(0,1));
	while(!Q.empty())
	{
		int cur=Q.top().second,cost=-Q.top().first;
		Q.pop();
		
		if(vis[cur])
			continue;
//		printf("cost=%d cur=%d\n",cost,cur);
		vis[cur]=true;
		ans=ans+cost;
		
		Update(cur);
	}
	
	printf("%I64d\n",ans);
	return 0;
}