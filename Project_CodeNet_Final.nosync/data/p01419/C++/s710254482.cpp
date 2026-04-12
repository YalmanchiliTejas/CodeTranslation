#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int MaxR=52;
const int MaxM=1020;

struct Node {
    int x,y;
}m[MaxM],p[MaxR][MaxR];

int R,C,M,Ans;
char a[MaxR][MaxR];
int b[MaxR][MaxR],c[MaxR][MaxR],d[MaxR][MaxR],t[MaxR][MaxR];
bool Vis[MaxR][MaxR];

bool InM(int x,int y)
{
    return x>=0 && x<R && y>=0 && y<C;
}

void BFS(int sx,int sy,int gx,int gy)
{
    memset(Vis,0,sizeof(Vis));
    memset(p,0,sizeof(p));
    queue<Node> Q;
    Node Qf,Nt;
    Nt.x = sx;
    Nt.y = sy;
    Q.push(Nt);
    Vis[sx][sy] = true;
    while ( !Q.empty() )
    {
        Qf = Q.front();
        Q.pop();
        for ( int i=0;i<4;i++ )
        {
            Nt.x = Qf.x+dir[i][0];
            Nt.y = Qf.y+dir[i][1];
            if ( InM(Nt.x,Nt.y) && a[Nt.x][Nt.y]=='.' && !Vis[Nt.x][Nt.y] )
            {
                Q.push(Nt);
                Vis[Nt.x][Nt.y] = true;
                p[Nt.x][Nt.y].x = Qf.x;
                p[Nt.x][Nt.y].y = Qf.y;
                if ( Nt.x==gx && Nt.y==gy )  return ;
            }
        }
    }
}

int DFS(int sx,int sy,int gx,int gy)
{
    if ( sx==gx && sy==gy )
    {
        return t[sx][sy];
    }
    int tt=DFS(sx,sy,p[gx][gy].x,p[gx][gy].y)+1;
    Ans += c[gx][gy]+d[gx][gy];
    if ( t[gx][gy] )
    {
        if ( c[gx][gy]+d[gx][gy]>(tt-t[gx][gy])*b[gx][gy] )
            Ans += (tt-t[gx][gy])*b[gx][gy]-(c[gx][gy]+d[gx][gy]);
    }
    return  t[gx][gy]=tt;
}

int main()
{
    while ( scanf("%d %d %d",&R,&C,&M)!=EOF )
    {
        for ( int i=0;i<R;i++ )
            scanf("%s",a[i]);
        for ( int i=0;i<R;i++ )
         for ( int j=0;j<C;j++ )
            scanf("%d",&b[i][j]);
        for ( int i=0;i<R;i++ )
         for ( int j=0;j<C;j++ )
            scanf("%d",&c[i][j]);
        for ( int i=0;i<R;i++ )
         for ( int j=0;j<C;j++ )
            scanf("%d",&d[i][j]);
        for ( int i=0;i<M;i++ )
            scanf("%d %d",&m[i].x,&m[i].y);
        memset(t,0,sizeof(t));
        t[m[0].x][m[0].y] = 1;
        Ans = c[m[0].x][m[0].y]+d[m[0].x][m[0].y];
        for ( int i=0;i<M-1;i++ )
        {
            BFS(m[i].x,m[i].y,m[i+1].x,m[i+1].y);
            DFS(m[i].x,m[i].y,m[i+1].x,m[i+1].y);
        }
        printf("%d\n",Ans);
    }
    return 0;
}