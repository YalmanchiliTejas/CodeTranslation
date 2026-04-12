#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,b[111][111],k,p;
char a[111][111];
int main()
{
    FAST_IO;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<m;j++)
            if(a[i][j]=='.')
                k++;
        if(k==m)
        {
            for(int j=0;j<m;j++)
                b[i][j]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
            if(a[j][i]=='.')
                k++;
        if(k==n)
            for(int j=0;j<n;j++)
                b[j][i]=1;
    }
    for(int i=0;i<n;i++)
    {p=0;
        for(int j=0;j<m;j++)
        {

            if(b[i][j]==0)
            {
                p=1;
                cout<<a[i][j];
            }


        }
        if(p==1)
        cout<<endl;
    }
}
