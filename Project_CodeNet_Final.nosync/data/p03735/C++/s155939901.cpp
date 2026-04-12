#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for (i=a;i<=b;i++)
typedef long long ll;
#define maxd 1e9+7
int n;
multiset<ll> a,b;
struct node{
    int x,y;
}ball[200500];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

ll query()
{
    return ((*a.rbegin()-*a.begin())*(*b.rbegin()-*b.begin()));
}

bool cmp(node p,node q)
{
    return ((p.x<q.x) || ((p.x==q.x) && (p.y<q.y)));
}

int main()
{
    n=read();int i;
    for (i=1;i<=n;i++)
    {
        ball[i].x=read();ball[i].y=read();
        if (ball[i].x>ball[i].y) swap(ball[i].x,ball[i].y);
        a.insert(ball[i].x);
        b.insert(ball[i].y);
    }
    ll ans=query();
    sort(ball+1,ball+1+n,cmp);
    for (i=1;i<=n;i++)
    {
        int nx=ball[i].x,ny=ball[i].y;
        a.erase(a.find(nx));b.erase(b.find(ny));
        a.insert(ny);b.insert(nx);
        ans=min(ans,query());
    }
    printf("%lld",ans);
    return 0;
}