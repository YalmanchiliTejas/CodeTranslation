#include <bits/stdc++.h>
#define NMAX 3005
using namespace std;
int n;
long long a[NMAX],d[NMAX][NMAX];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        d[i][i]=a[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            d[j][j+i-1]=max(a[j]-d[j+1][j+i-1],a[j+i-1]-d[j][j+i-2]);
        }
    }
    cout<<d[1][n];
    return 0;
}
