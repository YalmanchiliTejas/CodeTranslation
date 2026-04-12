#include<bits/stdc++.h>
using namespace std;
const int xp=1e9+7;
long long d[2][3002][3002],n,v[3002];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=n;i>=1;i--)
    for(int j=i;j<=n;j++)
    {
        d[1][i][j]=min(d[0][i+1][j]-v[i],d[0][i][j-1]-v[j]);
        d[0][i][j]=max(d[1][i+1][j]+v[i],d[1][i][j-1]+v[j]);
    }
    cout<<d[0][1][n];
}
