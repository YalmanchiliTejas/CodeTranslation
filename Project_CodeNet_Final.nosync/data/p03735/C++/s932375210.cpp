#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N=2e5+10;

struct Node
{
	int x,y;
	Node (int x=0,int y=0):x(x),y(y){}
	bool operator < ( const Node &A ) const { return x<A.x || (x==A.x && y<A.y); }
}P[N],Q[N<<1];

int n,Mx,Mn;

void Init()
{
	scanf("%d",&n);
	Mx=-1e9-10,Mn=1e9+10;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&P[i].x,&P[i].y);
		if (P[i].x>P[i].y) swap(P[i].x,P[i].y);
		Mx=max(P[i].y,Mx); Mn=min(P[i].x,Mn);
	}
}

int app[N],cnt;

void Add(int pos,int v)
{
	if (app[pos]) cnt--;
	app[pos]+=v;
	if (app[pos]) cnt++;
}

bool Can(int pos)
{
	if (cnt!=n) return 0;
	if (app[pos]>1) return 1;
	else return 0;
}

void Solve()
{
	int XMx=Mx,XMn=Mx,YMx=Mn,YMn=Mn;
	for (int i=1;i<=n;++i)
		XMn=min(XMn,P[i].y),YMx=max(YMx,P[i].x);
	LL ans=1ll*(XMx-XMn)*(YMx-YMn);
	int top=0;
	for (int i=1;i<=n;++i) Q[++top]=Node(P[i].x,i),Q[++top]=Node(P[i].y,i);
	sort(Q+1,Q+top+1);
	int h=1;cnt=0;
	for (int i=1;i<=top;++i)
	{
		Add(Q[i].y,1);
		while (Can(Q[h].y)) Add(Q[h].y,-1),++h;
		if (cnt==n) ans=min(ans,1ll*(Mx-Mn)*(Q[i].x-Q[h].x));
	}
	printf("%lld\n",ans);
}

int main()
{
	Init();
	Solve();
	return 0;
}