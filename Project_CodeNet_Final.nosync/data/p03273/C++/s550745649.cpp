#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
    int i,j,k,l;
    vector < vector < char > > a(n);
    for (i=0;i<n;i++)
    {
        vector < char > tmp(m,'.');
        a[i]=tmp;
    }
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            cin>>a[i][j];
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            if (a[i][j]=='.'||a[i][j]=='_')
            {
                int tag=0;
                for (k=0;k<n;k++)
                    if (a[k][j]=='.'||a[k][j]=='_') ;
                    else {tag=1;break;}
                if (!tag)
                {
                    for (k=0;k<m;k++)
                        if (a[i][k]=='.'||a[i][k]=='_') ;
                        else {tag=1;break;}
                    if (!tag)
                    {
                        for (k=0;k<n;k++)
                            a[k][j]='_';
                        for (k=0;k<m;k++)
                            a[i][k]='_';
                    }
                }
            }
    for (i=0;i<n;i++)
    {
        int tag=0;
        for (j=0;j<m;j++)
            if (a[i][j]!='_') {tag=1;cout<<a[i][j];}
        if (tag) cout<<endl;
    }
}
int main()
{
    while(cin>>n>>m)
        solve();
}