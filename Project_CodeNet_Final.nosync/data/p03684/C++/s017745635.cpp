#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int nmax=100005;
struct coord
{
    int val,ind;
}x[nmax],y[nmax];
bool comp(coord unu,coord doi)
{
    return unu.val<doi.val;
}
struct muchie
{
    int a,b,c;
}v[2*nmax];
int tt[nmax],rg[nmax];
int n,m,i,j;
long long cost;
bool comp_m(muchie unu,muchie doi)
{
    return unu.c<doi.c;
}
int finds(int x)
{
    int y=x,aux=0;
    while(x!=tt[x])
        x=tt[x];
    while(y!=x)
    {
        aux=tt[y];
        tt[y]=x;
        y=aux;
    }
    return x;
}
void unite(int A,int B)
{
    if(rg[A]>rg[B]) tt[B]=A;
    else tt[A]=B;
    if(rg[A]==rg[B]) rg[B]++;
}
int main()
{
    //freopen("data.in","r",stdin);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x[i].val>>y[i].val;
        x[i].ind=i;y[i].ind=i;
    }
    sort(x+1,x+n+1,comp);
    sort(y+1,y+n+1,comp);
    for(i=1;i<n;i++)
    {
        m++;
        v[m].a=x[i].ind;
        v[m].b=x[i+1].ind;
        v[m].c=x[i+1].val-x[i].val;
        m++;
        v[m].a=y[i].ind;
        v[m].b=y[i+1].ind;
        v[m].c=y[i+1].val-y[i].val;
    }
    sort(v+1,v+m+1,comp_m);
    for(i=1;i<=n;i++)
        tt[i]=i;
    for(i=1;i<=m;i++)
    {
        if(finds(v[i].a)!=finds(v[i].b))
        {
            unite(finds(v[i].a),finds(v[i].b));
            cost+=1LL*v[i].c;
        }
    }
    cout<<cost;
    return 0;
}
