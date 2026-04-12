#include<bits/stdc++.h>
#define pp pair<int,int>
#define MZ 1000000007
#define pq priority_queue
using namespace std;
struct Edge
{
    int dis,u,v;
    friend bool operator <(Edge x1,Edge x2)
    {
        return x1.dis>x2.dis;
    }
}temp;
struct Node
{
    int x,y,no;
}num[100005];
int root[100005];
bool cmp1(Node x1,Node x2)
{
    return x1.x<x2.x;
}
bool cmp2(Node x1,Node x2)
{
    return x1.y<x2.y;
}
pq <Edge> q;
int findr(int x)
{
    if(root[x]==x)
        return x;
    else
        return root[x]=findr(root[x]);
}
int main()
{
    int u,v;
    long long ans=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&num[i].x,&num[i].y);
        num[i].no=i+1;
        root[i+1]=i+1;
    }
    sort(num,num+n,cmp1);
    for(int i=1;i<n;i++)
    {
        temp.u=num[i].no;
        temp.v=num[i-1].no;
        temp.dis=num[i].x-num[i-1].x;
        q.push(temp);
    }
    sort(num,num+n,cmp2);
    for(int i=1;i<n;i++)
    {
        temp.u=num[i].no;
        temp.v=num[i-1].no;
        temp.dis=num[i].y-num[i-1].y;
        q.push(temp);
    }
    while(!q.empty())
    {
        temp=q.top();
        q.pop();
        u=findr(temp.u);
        v=findr(temp.v);
        if(u!=v)
        {
            root[u]=v;
            ans+=temp.dis;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
