#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string a[200];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n;i++)
        cin>>a[i];
    int i,j;
    while (1)
    {
        int ff=0;
        for ( i=1; i<=n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (a[i][j]!='.') break;
            }
            if (j==m)
            {
                ff=1; break;
            }
        }
        if (ff==0) break;
        for ( i=1; i<=n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (a[i][j]!='.') break;
            }
            if (j==m)
            {
                for (int k=i;k<=n;k++)
                    a[k]=a[k+1];
                n--;
            }
        }
    }
   /* cout<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<endl;*/
    while (1)
    {
        int ff=0;
        for (j=0; j<m; j++)
        {
            for (i=1; i<=n;i++)
            {
                if (a[i][j]!='.') break;
            }
            if (i==n+1)
            {   ff=1; break;}
        }
        if (ff==0) break;
        for (j=0; j<m; j++)
        {
            for (i=1; i<=n;i++)
            {
                if (a[i][j]!='.') break;
            }
            if (i==n+1)
            {
                m--;
                for (int k=1;k<=n;k++)
                {
                    for (int u=j;u<m;u++)
                        a[k][u]=a[k][u+1];
                    a[k][m]=0;
                }
                //break;
            }
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
