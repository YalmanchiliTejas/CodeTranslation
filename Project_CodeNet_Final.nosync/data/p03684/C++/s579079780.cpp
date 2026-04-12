# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <string>
# include <queue>
# define R register int
# define ll long long
# define pac(a,b) make_pair(a,b)

using namespace std;

const int maxn=200005;
int n,m,h,d[maxn],vis[maxn],f[maxn];
int sx[maxn],sy[maxn],a,b;
ll ans=0;
struct node { int v,id; }X[maxn],Y[maxn];
typedef pair <int,int> pii;
priority_queue <pii,vector<pii>,greater<pii> > q1,q2;

bool cmp (node a,node b) { return a.v<b.v; }

int find (int x) { if(x!=f[x]) return f[x]=find(f[x]); return x; }

int main()
{
    scanf("%d",&n);
    for (R i=1;i<=n;++i)
    {
        scanf("%d%d",&X[i].v,&Y[i].v);
        X[i].id=i;
        Y[i].id=i;
    }
    sort(X+1,X+1+n,cmp);
    sort(Y+1,Y+1+n,cmp);
    for (R i=1;i<n;++i)
		q1.push(pac(X[i+1].v-X[i].v,i)),sx[i]=1;
    for (R i=1;i<n;++i)
        q2.push(pac(Y[i+1].v-Y[i].v,i)),sy[i]=1;
    int s=0;
    for (R i=1;i<=n;++i) f[i]=i;
    while(s!=n-1)
    {
        int x=q1.top().first;
        int y=q2.top().first;
        if(x<y)
        {
            a=q1.top().second;
            q1.pop();
            b=a+sx[a];
			x=X[a].id; y=X[b].id;
			x=find(x),y=find(y);
			if(x!=y) f[x]=y,s++,ans+=X[a+sx[a]].v-X[a].v;
            if(a+sx[a]+1>n) continue;
            sx[a]++;
            q1.push(pac(X[a+sx[a]].v-X[a].v,a));
        }
        else
        {
            a=q2.top().second;
            q2.pop();
            b=a+sy[a];
			x=Y[a].id; y=Y[b].id;
			x=find(x),y=find(y);
			if(x!=y) f[x]=y,s++,ans+=Y[a+sy[a]].v-Y[a].v;
            if(a+sy[a]+1>n) continue;
            sy[a]++;
            q2.push(pac(Y[a+sy[a]].v-Y[a].v,a));
        }
    }
    printf("%lld\n",ans);
    return 0;
}