#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
char c[105][105];
bool pdx[105],pdy[105];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>c[i][j];
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=1;j<=m;j++)
            if(c[i][j]=='#')
                {flag=1;break;}
        if(flag==0)
            pdx[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        bool flag=0;
        for(int j=1;j<=n;j++)
            if(c[j][i]=='#')
                {flag=1;break;}
        if(flag==0)
            pdy[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(pdx[i]==0&&pdy[j]==0)
                cout<<c[i][j];
        if(!pdx[i])
            cout<<endl;
    }
    return 0;
}