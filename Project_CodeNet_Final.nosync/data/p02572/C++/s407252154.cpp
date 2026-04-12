#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
int main()
{
    long long n,a[200005],i,j,s,m,total=0,d[200005];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        total+=(a[i]%mod);
        total%=mod;
    }
    for(i=1;i<n;i++)
    {
        d[i]=total-(a[i]%mod);
        d[i]=((d[i]%mod)+mod)%mod;
        total=d[i];
    }
    total=0;
    for(i=1;i<n;i++)
    {
        total+=(((a[i]%mod)*d[i])%mod);
        total%=mod;
    }
    cout<<total<<endl;
    return 0;
}