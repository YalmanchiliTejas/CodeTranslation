#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include<queue>
#include <string>
#include<algorithm>
#define N 250000
#define MOD 1000000007
using namespace std;
int cas;
int n,m;
struct ds{int x,y,i;}d[N];
bool cmpx(ds d1,ds d2){return d1.x<d2.x;}
bool cmpy(ds d1,ds d2){return d1.y<d2.y;}
struct es{int i,j,c;}e[N];
bool cmp(es d1,es d2){return d1.c<d2.c;}
int p[N];
int getf(int x)
{
    int i=x,j;
    while(p[i]!=i)i=p[i];
    while(p[x]!=i){j=p[x];p[x]=i;x=j;}
    return i;
}
void merge(int a,int b)
{
    a=getf(a);b=getf(b);
    p[a]=b;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        d[i].i=i;
        p[i]=i;
        scanf("%d%d",&d[i].x,&d[i].y);
    }
    sort(d+1,d+n+1,cmpx);
    for(int i=1;i<n;i++)
    {
        e[i].i=d[i].i;
        e[i].j=d[i+1].i;
        e[i].c=d[i+1].x-d[i].x;
    }
    sort(d+1,d+n+1,cmpy);
    for(int i=1;i<n;i++)
    {
        e[i+n-1].i=d[i].i;
        e[i+n-1].j=d[i+1].i;
        e[i+n-1].c=d[i+1].y-d[i].y;
    }
    sort(e+1,e+2*n-1,cmp);
    long long ans=0,cnt=0;
    for(int i=1;i<=2*n-2;i++)
    {
        if(getf(e[i].i)!=getf(e[i].j))
        {
            merge(e[i].i,e[i].j);
            ans+=e[i].c;
            cnt++;
            if(cnt==n-1){cout<<ans;return 0;}
        }
    }
}


