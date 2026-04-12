#include<bits/stdc++.h>
using namespace std;
char a[100][100];
bool vis[1001][100];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    if (a[0][0]!='#')
        cout<<"Impossible"<<endl;
    else
    {
        int x=0,y=0;
        vis[x][y]=1;
        while(1)
        {
            if (x+1<n && a[x+1][y]=='#' ) vis[x+1][y]=1,x++;
            else if (y+1<m && a[x][y+1]=='#' ) vis[x][y+1]=1,y++;
            else break;
        }
        if (x!=n-1 && y!=m-1){
            cout<<"Impossible"<<endl;
            return 0;
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (vis[i][j]==0 && a[i][j]=='#')
                {
                    cout<<"Impossible"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Possible"<<endl;
    }
}
