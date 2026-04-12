/*
 * @Author: clorf 
 * @Date: 2020-08-29 17:07:51 
 * @Last Modified by: clorf
 * @Last Modified time: 2020-08-29 17:31:41
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctime>
#define INF 1e9
using namespace std;
const int maxn=100010;
const double Pi=acos(-1.0);
template<class T>void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
int n,ans,fa[maxn],cnt;
struct city
{
    int x;
    int y;
    int id;
}e[maxn];
struct edge
{
    int x;
    int y;
    int z;
}s[maxn];
bool cmp(edge a,edge b)
{
    return a.z<b.z;
}
inline int dis(int a,int b,int c,int d)
{
    return min(abs(a-c),abs(b-d));
} 
inline bool cmp1(city a,city b)
{
    return a.x<b.x;
}
inline bool cmp2(city a,city b)
{
    return a.y<b.y;
}
int getfa(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=getfa(fa[x]);

}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&e[i].x,&e[i].y);
        e[i].id=i;
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(e+1,e+n+1,cmp1);
    for(int i=2;i<=n;i++)
        s[++cnt]=(edge){e[i].id,e[i-1].id,dis(e[i].x,e[i].y,e[i-1].x,e[i-1].y)};
    sort(e+1,e+n+1,cmp2);
    for(int i=2;i<=n;i++)
        s[++cnt]=(edge){e[i].id,e[i-1].id,dis(e[i].x,e[i].y,e[i-1].x,e[i-1].y)};
    sort(s+1,s+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int x=getfa(s[i].x);
        int y=getfa(s[i].y);
        if(x!=y)
        {
            fa[x]=y;
            ans+=s[i].z;
        }
    }
    printf("%d",ans);
    return 0;
}