#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dir[2][2]={
   0,1,
   1,0
};
char vp[10][10];int flag;
 int h,w;
 int vis[10][10];
struct node{
    int x,y;
};
queue<node>q;
void bfs()
{
    while(!q.empty())
    {
        int sum=0;
        node temp,k;
        temp=q.front();
        q.pop();
        if(temp.x==h&&temp.y==w)
            flag=1;
        for(int i=0;i<2;i++)
        {
            if(vp[temp.x+dir[i][0]][temp.y+dir[i][1]]=='#')
            {
                k.x=temp.x+dir[i][0];
                k.y=temp.y+dir[i][1];
                q.push(k);
                vis[k.x][k.y]=1;
                sum++;
            }
        }
        if(sum==2)
        {
            flag=0;
            break;
        }
    }

}
int main()
{
    scanf("%d %d ",&h,&w);
    node temp;
    temp.x=temp.y=1;
    vis[1][1]=1;
    q.push(temp);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
            scanf("%c",&vp[i][j]);
        getchar();
    }
    bfs();
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(vp[i][j]=='#'&&vis[i][j]==0)
            {
                flag=0;
            }
        }
        if(flag==0)
            break;
    }
    if(flag==1)
    {
        printf("Possible");
    }

    else
        printf("Impossible");
}