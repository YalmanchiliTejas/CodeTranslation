#include <bits/stdc++.h>#De
#define DIM 3007
#define INF 1000000000000000007LL
using namespace std;

long long n,a[DIM],d[DIM][DIM];

long long F(int l,int r)
{
    if(d[l][r]!=INF) return d[l][r];
    if(l==r) d[l][r] = a[l];
    else
    {
        d[l][r] = max(a[l]-F(l+1,r),a[r]-F(l,r-1));
    }
    return d[l][r];
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j)
        d[i][j] = INF;
    cout<<F(1,n);
    return 0;
}
