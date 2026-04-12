#include<bits/stdc++.h>

using namespace std;

#define sp << " " <<

long long a[3000];

long long r(long long n)
{
    long long dp[n][n];
    for(long long i=0;i<n;i++)
    {
        for(long long d=0,p=i;p<n;d++,p++)
        {
            long long s=((d+2)<=p)?dp[d+2][p]:0;
            long long h=((d+1)<=(p-1))?dp[d+1][p-1]:0;
            long long t=(d<=(p-2))?dp[d][p-2]:0;
            dp[d][p]=max(a[d]+min(s,h),a[p]+min(h,t));
        }
    }
    return dp[0][n-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,b=0;
    cin >> n;
    for(long long d=0;d<n;d++)
    {
        cin >> a[d];
        b+=a[d];
    }
    long long m=r(n);
    cout << 2*m-b;
    return 0;
}