//Hi =)) I'm T.A
#include <bits/stdc++.h>
#define nmax 200002
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define reset(a,x) memset(a,x,sizeof(a))
#define task "built"

using namespace std;
const int MOD=1e9+7;

int n,cnt(0),root[nmax];
ll res(0);

struct on
{
    int u,v,w;
}b[nmax];

struct in
{
    int x,y,vt;
}a[nmax];

bool sx1(in a, in b)
{
    return a.x<b.x;
}

bool sx2(in a, in b)
{
    return a.y<b.y;
}

bool sx3(on a, on b)
{
    return a.w<b.w;
}

int getroot(int u)
{
    return root[u]?(root[u]=getroot(root[u])):u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
   // freopen(task".inp","r",stdin);
   // freopen(task".out","w",stdout);
      cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,a[i].vt=i;
    sort(a+1,a+1+n,sx1);
    for(int i=1;i<n;i++)
        b[++cnt]={a[i].vt,a[i+1].vt,a[i+1].x-a[i].x};
    sort(a+1,a+1+n,sx2);
    for(int i=1;i<n;i++)
    b[++cnt]={a[i].vt,a[i+1].vt,a[i+1].y-a[i].y};
    sort(b+1,b+2*n,sx3);
    for(int i=1;i<2*n;i++)
    {
        int p=getroot(b[i].u);
        int q=getroot(b[i].v);
        if(p!=q)
        {
            root[p]=q;
            res+=1ll*b[i].w;
        }
    }
    cout<<res;

    return 0;
}
