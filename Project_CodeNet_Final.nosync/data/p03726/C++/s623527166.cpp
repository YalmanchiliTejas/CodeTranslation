#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,m,d[maxn];
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}

int fa[maxn],dep[maxn];
void dfs(const int x)
{
    for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
        dep[y]=dep[x]+1,fa[y]=x,dfs(y);
}

int col[maxn];
struct node{int d,x;};
inline bool operator <(const node x,const node y){return x.d<y.d;}
priority_queue<node>q;
bool Col()
{
    for(int i=1;i<=n;i++) q.push((node){dep[i],i});
    memset(col,-1,sizeof col);
    while(!q.empty())
    {
        const node now=q.top(); q.pop();
        int x=now.x;
        if(col[x]!=-1) continue;
        if(x==1) {col[x]=0;return true;}
        if(col[fa[x]]!=-1) return true;
        col[fa[x]]=0;
        col[x]=1;
        d[fa[x]]=1;
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        ins(x,y); ins(y,x);
    }
    dep[1]=1; dfs(1);
    if(Col()) return puts("First"),0;
   // for(int i=1;i<=n;i++) if(!col[i]&&!d[i]) return puts("First"),0;
    puts("Second");

    return 0;
}
/*
3
1 2
2 3
*/