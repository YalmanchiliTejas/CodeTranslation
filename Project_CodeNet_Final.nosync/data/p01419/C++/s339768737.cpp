#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 50 + 3;
int mat[maxn][maxn],n,m,q;
int on[maxn][maxn];
int off[maxn][maxn];
int t[maxn][maxn];
int ptr[maxn][maxn];
vector<int>PPP[maxn][maxn];

char s[maxn][maxn];

struct node
{
    int x,y;
};
node mis[1200];
vector<node> Q;

vector<node> P;

int Flag=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int vis[maxn][maxn];
void dfs(int x,int y,int xx,int yy)
{
    if(Flag)return;
    if(x==xx&&y==yy)
    {
        int stary = 0;

        for(int i=1;i<P.size();i++)
            Q.push_back(P[i]);
        Flag=1;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int xxx = x+dx[i];
        int yyy = y+dy[i];
        if(xxx<=0||xxx>n)continue;
        if(yyy<=0||yyy>m)continue;
        if(vis[xxx][yyy])continue;
        if(s[xxx][yyy]=='#')continue;
        node ttt;ttt.x=xxx;ttt.y=yyy;
        P.push_back(ttt);
        vis[xxx][yyy]=1;
        dfs(xxx,yyy,xx,yy);
        P.pop_back();
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&t[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&on[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&off[i][j]);

    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&mis[i].x,&mis[i].y);
        mis[i].x++;mis[i].y++;
    }
    Q.push_back(mis[1]);
    for(int i=1;i<q;i++)
    {
        memset(vis,0,sizeof(vis));
        Flag=0;
        P.clear();
        vis[mis[i].x][mis[i].y]=1;
        node k;k.x=mis[i].x,k.y=mis[i].y;
        P.push_back(k);
        dfs(mis[i].x,mis[i].y,mis[i+1].x,mis[i+1].y);
    }
    for(int i = 0 ; i < Q.size() ; ++ i)
    {
        node cur = Q[i];
        int x = cur.x , y = cur.y;
        PPP[x][y].push_back(i);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= m ; ++ j)
         if(PPP[i][j].size() != 0)
    {
        ans += on[i][j]; ans += off[i][j];
        for(int z = 0 ; z < PPP[i][j].size() - 1 ; ++ z)
        {
            int dis = PPP[i][j][z+1] - PPP[i][j][z];
            ans += min(dis * t[i][j] , off[i][j] + on[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}