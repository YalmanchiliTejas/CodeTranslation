#include<cstdio>
#include<iostream>
using namespace std;
char a[1008][1008];
bool vis[2][1008];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
            if(a[i][j]=='#')
            {
                vis[0][i]=true;
                vis[1][j]=true;
            }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
            if(vis[0][i]&&vis[1][j])cout<<a[i][j];
        if(vis[0][i])cout<<endl;
    }
    return 0;
}
