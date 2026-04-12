#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    char a[102][102];
    int visit[102];
    int visit2[102];
    while(cin>>n>>m)
    {
        memset(visit,0,sizeof(visit));
        memset(visit2,0,sizeof(visit2));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                if(a[i][j]=='#')
                {
                    visit[i]=1;
                    visit2[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]==1)
            {
                continue;
            }
            for(int j=0;j<m;j++)
            {
                a[i][j]='o';
            }
        }
        for(int i=0;i<m;i++)
        {
            if(visit2[i]==1)
            {
                continue;
            }
            for(int j=0;j<n;j++)
            {
                a[j][i]='o';
            }
        }
        int x;
        for(int i=0;i<n;i++)
        {
            x=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!='o')
                {
                    cout<<a[i][j];
                    x++;
                }

            }
            if(x!=0)
                cout<<endl;
        }
    }
    return 0;
}
