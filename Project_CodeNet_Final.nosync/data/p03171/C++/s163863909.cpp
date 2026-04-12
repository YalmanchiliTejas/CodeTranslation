#include <bits/stdc++.h>
using namespace std;

long memo[2][3010][3010], n, a[3010], sum[3010];

long func(int taro, int i, int j)
{
    long& res=memo[taro][i][j];
    if (res<LONG_MAX) return res;

    res=0;
    if (i<=j) res=max(res, a[i]+sum[j+1]-sum[i+1]-func(!taro, i+1, j));
    if (j>=i) res=max(res, a[j]+sum[j]-sum[i]-func(!taro, i, j-1));
    return res;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
        for(int j=0; j<n; ++j) for(int k=0; k<2; ++k) memo[k][i][j]=LONG_MAX;
    }
    auto X=func(1, 0, n-1);
    auto Y=sum[n]-X;
    cout<<X-Y<<endl;
}
