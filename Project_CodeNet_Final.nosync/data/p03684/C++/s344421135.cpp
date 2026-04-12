#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=1e5+10;
#define x first
#define y second
#define mp make_pair

int n;
pair<pii,int> pos[maxn];
LL ans;
int fa[maxn];
vector<pair<int,pii> > edg;

bool cmpx(pair<pii,int> a,pair<pii,int> b)
{
	return a.x.x<b.x.x;
}

bool cmpy(pair<pii,int> a,pair<pii,int> b)
{
	return a.x.y<b.x.y;
}

int father(int p)
{
	if (fa[p]==p) return p;
	else return fa[p]=father(fa[p]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&pos[i].x.x,&pos[i].x.y);
		pos[i].y=i;
	}
	
	sort(pos+1,pos+n+1,cmpx);
	for(int i=1;i<n;i++)
		edg.push_back(mp(pos[i+1].x.x-pos[i].x.x,mp(pos[i+1].y,pos[i].y)));
	sort(pos+1,pos+n+1,cmpy);
	for(int i=1;i<n;i++)
		edg.push_back(mp(pos[i+1].x.y-pos[i].x.y,mp(pos[i+1].y,pos[i].y)));
	
	ans=0;
	sort(edg.begin(),edg.end());
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<edg.size();i++)
	{
		int tx=edg[i].y.x,ty=edg[i].y.y;
		if (father(tx)!=father(ty))
		{
			ans+=LL(edg[i].x);
			fa[father(tx)]=father(ty);
		}
	}
	
	printf("%I64d\n",ans);
	return 0;
}