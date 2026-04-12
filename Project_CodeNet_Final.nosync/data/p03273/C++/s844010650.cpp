#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 109
bool vis[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    char a[N][N];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int c=0;
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='.')
            {
                c++;
            }
            if(c==m)
            {
                for(int k=1; k<=m; k++)
                    vis[i][k]=true;
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        int d=0;
        for(int j=1; j<=n; j++)
        {
            if(a[j][i]=='.')
            {
                d++;
            }
            if(d==n)
            {
                for(int k=1; k<=n; k++)
                    vis[k][i]=true;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int x=0;
        for(int j=1; j<=m; j++)
        {
            if(vis[i][j]==false){
                cout<<a[i][j];
                x++;
            }
        }
        if(x!=0)
        cout<<endl;
    }
    return 0;
}
