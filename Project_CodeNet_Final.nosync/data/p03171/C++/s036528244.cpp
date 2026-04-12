#include <bits/stdc++.h>

using namespace std;

long long n,i,j,v[3010],d[3010][3010];
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
        d[i][i]=v[i];
    }

    for(i=n; i>=1; i--)
    {
        for(j=i+1; j<=n; j++)
        {
            if(i+1<=n)d[i][j]=max(-d[i+1][j]+v[i],-d[i][j-1]+v[j]);
            else d[i][j]=-d[i][j-1]+v[j];
        }
    }

    cout<<d[1][n];
    return 0;
}
