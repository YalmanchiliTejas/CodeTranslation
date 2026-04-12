#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
struct node
{
    long long x, y;
}nod[100010];
struct nodex
{
    int id;
    long long x;
    friend bool operator < (const nodex &a,const nodex &b)
    {
        return a.x<b.x;
    }
}nodx[100010];
struct nodey
{
    int id;
    long long y;
    friend bool operator < (const nodey &a,const nodey &b)
    {
        return a.y<b.y;
    }
}nody[100010];
struct edge
{
    long long val;
    int u,v;
    friend bool operator < (const edge &a,const edge &b)
    {
        return a.val<b.val;
    }
}e[300010];
int k=0;

void init()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>nod[i].x>>nod[i].y;
        nodx[i].id=i+1;nodx[i].x=nod[i].x;
        nody[i].id=i+1;nody[i].y=nod[i].y;
    }
    sort(nodx,nodx+n);
    sort(nody,nody+n);
    for(int i=0;i<n-1;i++)
    {
        int next_i=i;
        for(int j=i+1;j<n;j++)
        {
            if(nodx[i].x!=nodx[j].x)
            {
                next_i=j-1;
                break;
            }
            e[k].u=nodx[i].id;
            e[k].v=nodx[j].id;
            e[k++].val=0;
            if(j==n-1)
            {
                next_i=j;
                break;
            }
        }
        if(next_i==n-1)break;
        e[k].u=nodx[i].id;
        e[k].v=nodx[next_i+1].id;
        e[k++].val=nodx[next_i+1].x-nodx[i].x;
        i=next_i;
    }
    for(int i=0;i<n-1;i++)
    {
        int next_i=i;
        for(int j=i+1;j<n;j++)
        {
            if(nody[i].y!=nody[j].y)
            {
                next_i=j-1;
                break;
            }
            e[k].u=nody[i].id;
            e[k].v=nody[j].id;
            e[k++].val=0;
            if(j==n-1)
            {
                next_i=j;
                break;
            }
        }
        if(next_i==n-1)break;
        e[k].u=nody[i].id;
        e[k].v=nody[next_i+1].id;
        e[k++].val=nody[next_i+1].y-nody[i].y;
        i=next_i;
    }
    sort(e,e+k);
}

int father[100010];
long long ans;

int findfather(int x)
{
    if(father[x]==x)return x;
    else return father[x]=findfather(father[x]);
}

void kruskal()
{
    for(int i=0;i<k;i++)
    {
        int u=e[i].u,v=e[i].v;
        int fu=findfather(u);
        int fv=findfather(v);
        if(fu==fv)continue;
        if(fu<fv)father[fv]=fu;
        else father[fu]=fv;
        ans+=e[i].val;
    }
}

int main()
{
    ans=0;
    init();
    for(int i=1;i<=n;i++)father[i]=i;
    kruskal();
    cout<<ans;
    return 0;
}



