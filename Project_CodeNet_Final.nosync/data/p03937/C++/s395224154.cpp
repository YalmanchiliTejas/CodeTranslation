#include<bits/stdc++.h>
using namespace std;
//const int maxx = 100010;
const int inf = 0x3f3f3f3f;
int n,m,sum=0,cnt=0,flag=0,x1,y5;
char a[10][10];
int vis[10][10];
int dis[2][2]= {{0,1},{1,0}};
void dfs(int p,int q)
{
    cnt++;
    if(cnt==sum)
    {
        flag=1;
        printf("Possible\n");
        return;
    }
    for(int i=0; i<2; i++)
    {
        if(a[p+dis[i][0]][q+dis[i][1]]=='#'&&p+dis[i][0]<=n&&q+dis[i][1]<=m)
        {
            dfs(p+dis[i][0],q+dis[i][1]);
            cnt--;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='#') sum++;
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]=='#')
            {
                dfs(i,j);
                if(flag==0) printf("Impossible\n");
                return 0;
            }

    return 0;
}
