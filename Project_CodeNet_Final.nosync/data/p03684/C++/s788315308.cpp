#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

struct punct
{
    int x,y;
    long long poz;
};

punct v[100010],v1[300010];
int vaz[100010],rad[100010];
map<pair<int,int>, char> vaz1;

int cmp1(punct a,punct b)
{
    return a.x<b.x;
}

int cmp2(punct a,punct b)
{
    return a.y<b.y;
}

int cmp3(punct a,punct b)
{
    return a.poz<b.poz;
}

int radacina(int x)
{
    int y=x;
    while(rad[y]!=y) y=rad[y];
    while(x!=y)
    {
        int aux=rad[x];
        rad[x]=y;
        x=aux;
    }
    return y;
}

void reuneste(int x,int y)
{
    int a=radacina(y),b=radacina(x);
    rad[b]=a;
}

int query(int x,int y)
{
    if(radacina(x)==radacina(y)) return 1;
    else return 0;
}

int main()
{
    int n;
    long long sol=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i].x,&v[i].y);
        v[i].poz=i;
        rad[i]=i;
    }
    int l=0;
    sort(v+1,v+n+1,cmp1);
    for(int i=1;i<n;i++)
        v1[++l]={v[i].poz,v[i+1].poz,v[i+1].x-v[i].x};
    sort(v+1,v+n+1,cmp2);
    for(int i=1;i<n;i++)
        v1[++l]={v[i].poz,v[i+1].poz,v[i+1].y-v[i].y};
    sort(v1+1,v1+l+1,cmp3);
    int c=1;
    for(int i=1;i<=l;i++)
    {
        if(query(v1[i].x,v1[i].y)==0) {sol+=v1[i].poz;reuneste(v1[i].x,v1[i].y);}
    }
    printf("%lld",sol);
    return 0;
}
