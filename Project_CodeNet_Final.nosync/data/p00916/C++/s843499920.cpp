#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int lenx,leny,vis[210][210],dist[4][2]= {0,1,1,0,0,-1,-1,0};
void dfs(int i,int j)
{
    if(vis[i][j]||i<0||i>lenx*2+3||j<0||j>=leny*2+3) return ;
    vis[i][j]=1;
    for(int k=0; k<4; k++)
    {
        int ii=i+dist[k][0];
        int jj=j+dist[k][1];
        dfs(ii,jj);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        memset(vis,0,sizeof(vis));
        int i,j,sum=0,a[153][5],v[55][5]={0},x[210],y[210];
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
            x[i*2]=a[i][0],x[i*2+1]=a[i][2];
            y[i*2]=a[i][1],y[i*2+1]=a[i][3];
        }
        sort(x,x+n*2);
        sort(y,y+n*2);
        lenx=unique(x,x+n*2)-x;
        leny=unique(y,y+n*2)-y;
        for(i=0; i<n; i++)
        {
            for(j=0; j<lenx; j++)
            {
                if(a[i][0]==x[j]&&!v[i][0]) a[i][0]=j*2+2,v[i][0]=1;
                if(a[i][2]==x[j]&&!v[i][2]) a[i][2]=j*2+2,v[i][2]=1;
            }
            for(j=0; j<leny; j++)
            {
                if(a[i][1]==y[j]&&!v[i][1]) a[i][1]=j*2+2,v[i][1]=1;
                if(a[i][3]==y[j]&&!v[i][3]) a[i][3]=j*2+2,v[i][3]=1;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=a[i][0]; j<=a[i][2]; j++)
                vis[j][a[i][1]]=1,vis[j][a[i][3]]=1;
            for(j=a[i][3]; j<=a[i][1]; j++)
                vis[a[i][0]][j]=1,vis[a[i][2]][j]=1;
        }
        /*for(i=0; i<lenx*2+2; i++)
            for(j=0; j<leny*2+2; j++)
                if(!vis[i][j]) dfs(i,j),sum++;
        printf("%d\n",sum);*/
         for(int i=0;i<lenx*2+2;i++)
            for(int j=0;j<leny*2+2;j++)
                  if(!vis[i][j])
                    {
                        dfs(i,j);
                         sum++;
                    }
        cout<<sum<<endl;
    }
    return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int vis[200][10],dis[4][2]={1,0,-1,0,0,1,0,-1};
int sum=0;
void dfs(int i,int j)
{
    if(vis[i][j]) return ;
    vis[i][j]=1;
    for(int k=0;k<4;k++)
    {
        int ix=i+dis[k][0];
        int iy=j+dis[k][1];
        dfs(ix,iy);
    }
}
int main()
{
    int n,lenx,leny;
    while(scanf("%d",&n)&&n)
    {
        memset(vis,0,sizeof(vis));
        int a[200][10],x[500],y[500],v;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
            x[i*2]=a[i][0];
            x[i*2+1]=a[i][2];
            y[i*2]=a[i][1];
            y[i*2+1]=a[i][3];
        }
        sort(x,x+n*2);
        sort(y,y+n*2);
        lenx=unique(x,x+n*2)-x;
        leny=unique(y,y+n*2)-y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<lenx;j++)
            {
                if(a[i][0]==x[j]&&!vis[i][0])
                {
                    a[i][0]=2*j+2;
                    vis[i][0]=1;
                }
                if(a[i][2]==x[j]&&!vis[i][2])
                {
                    a[i][2]=2*j+2;
                    vis[i][2]=1;
                }
            }
            for(int j=0;j<leny;j++)
            {
                if(a[i][1]==y[j]&&!vis[i][1])
                {
                    a[i][1]=2*j+2;
                    vis[i][1]=1;
                }
                if(a[i][3]==y[j]&&!vis[i][3])
                {
                    a[i][3]=2*j+2;
                    vis[i][3]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=a[i][0];j<=a[i][2];j++)
            {
                vis[j][a[i][1]]=1;
                vis[j][a[i][3]]=1;
            }
            for(int j=a[i][3];j<=a[i][1];j++)
            {
                vis[a[i][0]][j]=1;
                vis[a[i][2]][j]=1;
            }
        }
        for(int i=0;i<lenx*2+2;i++)
            for(int j=0;j<leny*2+2;j++)
                  if(!vis[i][j])
                    {
                        dfs(i,j);
                         sum++;
                    }
        cout<<sum<<endl;
    }
    return 0;
}*/