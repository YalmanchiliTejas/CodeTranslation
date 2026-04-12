# include<iostream>
# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N=100005;
const int INF=1<<30;
struct node{
	int x,y,v;
}line[100005];
bool cmp1(node p,node q)
{
	return p.x<q.x;
}
bool cmp2(node p,node q)
{
	return p.y<q.y;
}
struct edge
{
    int fr,to,w,nxt;
    bool operator < (const edge &a) const {
        return w<a.w;
    }
};
int pre[N],n,head[N],cnt;
edge e[500005+5];
void add(int fr,int to,int w)
{
    e[cnt].fr=fr;
    e[cnt].to=to;
    e[cnt].w=w;
    e[cnt].nxt=head[fr];
    head[fr]=cnt++;
}
int fin(int x)
{
    if(x==pre[x])
        return x;
    return pre[x]=fin(pre[x]);
}
void Kruskal()
{
    for(int i=1;i<=n;++i)
        pre[i]=i;
    sort(e,e+cnt);
    int ans=0;
    int p,q,s;
    for(int i=0;i<cnt;i++){
        int u=fin(e[i].fr);
        int v=fin(e[i].to);
        if(u!=v){
            pre[u]=v;
            ans+=e[i].w; 
        }
    }
    printf("%d\n",ans);
}
int main()
{
    int a,b,c,m;
    scanf("%d\n",&n);
    for (int i=1;i<=n;i++)
    {
    	scanf("%d%d\n",&line[i].x,&line[i].y);
    	line[i].v=i;
    }
    cnt=0;
    memset(head,-1,sizeof(head));
    sort(line+1,line+1+n,cmp1);
    for (int i=1;i<n;i++)
    {
        add(line[i].v,line[i+1].v,line[i+1].x-line[i].x);
        add(line[i+1].v,line[i].v,line[i+1].x-line[i].x);
    }
    sort(line+1,line+1+n,cmp2);
    for (int i=1;i<n;i++)
    {
        add(line[i].v,line[i+1].v,line[i+1].y-line[i].y);
        add(line[i+1].v,line[i].v,line[i+1].y-line[i].y);
    }
    Kruskal();
    return 0;
}