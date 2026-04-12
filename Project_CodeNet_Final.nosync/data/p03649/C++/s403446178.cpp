#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[51],n;
bool check(long long x1,long long x2)
{
    for(long long x=x1;x<=x2;++x)
    {
        long long ans=0;
        for(long long i=1;i<=n;++i)
            ans+=ceil(1.0L*(a[i]+x-n+1)/(n+1));
        if(ans<=x) return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    long long l=0,r=1e16+100,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid*n,mid*n+n-1))
            r=mid-1;
        else
            l=mid+1;
    }
    for(long long i=l*n;i<=l*n+n-1;++i)
        if(check(i,i)) 
        {
            cout<<i<<endl;
            return 0;
        }
    return 0;
}