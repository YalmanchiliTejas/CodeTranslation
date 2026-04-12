#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int fa[200006];
struct node
{
    int x,y,id;
}s[200006];
struct node2
{
    int qi,mo,bian;
}t[200006];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
bool cmp2(node a,node b)
{
    return a.y<b.y;
}
bool cmp3(node2 a,node2 b)
{
    return a.bian<b.bian;
}
int find(int x)
{
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}
void unio(int x,int y)
{
    int fx=find(x);int fy=find(y);
    if(fx!=fy)
    fa[fy]=fx;
}
int main()
{
    int q,n;long long int sum;
    scanf("%d",&n);
        q=0;sum=0;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&s[i].x,&s[i].y);
            s[i].id=i;
            fa[i]=i;
        }
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<n;i++)
        {
            ++q;
            t[q].qi=s[i].id;
            t[q].mo=s[i+1].id;
            t[q].bian=s[i+1].x-s[i].x;
        }
        sort(s+1,s+n+1,cmp2);

        for(int i=1;i<n;i++)
        {
            ++q;
            t[q].qi=s[i].id;
            t[q].mo=s[i+1].id;
            t[q].bian=s[i+1].y-s[i].y;
        }

        sort(t+1,t+q+1,cmp3);
        for(int i=1;i<=q;i++)
        {
            if(find(t[i].qi)!=find(t[i].mo))
            {
                sum=sum+t[i].bian;
                unio(t[i].qi,t[i].mo);
            }
        }
        printf("%lld\n",sum);

}
