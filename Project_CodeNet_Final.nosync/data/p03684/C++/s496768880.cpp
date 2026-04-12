#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define rep(i,x,y) for (int i=x;i<=y;i++)
#define dep(i,y,x) for (int i=y;i>=x;i--)
#define sz(x) (int)(x.size())

using namespace std;

typedef long long LL;   
typedef unsigned long long uLL;

const int maxn=200000+7;

struct Edge{
    int x,y;LL val;
} E[maxn*4];

int n,Esize,F[maxn],ux[maxn],uy[maxn],pos[maxn];
LL x[maxn],y[maxn];

bool cmpx(int a,int b) {return x[a]<x[b];}
bool cmpy(int a,int b) {return y[a]<y[b];}
bool cmp(Edge a,Edge b) {return a.val<b.val;}

int find(int k) {return (F[k]==k)?(k):(F[k]=find(F[k]));}

LL Kruskal()
{
    LL ans=0;int fx,fy;
    rep(i,1,Esize)
    {
        fx=find(E[i].x),fy=find(E[i].y);
        if (fx==fy) continue;

        ans+=E[i].val;
        F[fx]=fy;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld%lld",&x[i],&y[i]);

    rep(i,1,n) ux[i]=i,uy[i]=i;

    sort(ux+1,ux+n+1,cmpx); 
    sort(uy+1,uy+n+1,cmpy);

    rep(i,1,n) pos[uy[i]]=i;
    rep(i,1,n*2) F[i]=i;
    rep(i,1,n) F[pos[ux[i]]+n]=i;

    rep(i,1,n-1) E[++Esize]=(Edge){i,i+1,x[ux[i+1]]-x[ux[i]]};
    rep(i,1,n-1) E[++Esize]=(Edge){i+n,i+n+1,y[uy[i+1]]-y[uy[i]]};

    sort(E+1,E+Esize+1,cmp);

    printf("%lld\n",Kruskal());

    // system("pause");
    return 0;
}
