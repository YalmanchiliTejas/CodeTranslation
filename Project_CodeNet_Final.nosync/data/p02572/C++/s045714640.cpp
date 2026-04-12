#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
long long n;
void solve()
{
    long long i,j,a[n+1],b[n+1],ans=0;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=MOD;
    }
    a[0]=0;
    sort(a+1,a+n+1);
    for (i=0;i<=n;i++)
        b[i]=a[i];
    for (i=2;i<=n;i++)
        b[i]=(b[i-1]+b[i])%MOD;
    for (i=1;i<n;i++)
        ans=((ans+((MOD+b[n]-b[i])%MOD)*a[i])%MOD)%MOD;
    cout<<ans<<endl;
}
int main()
{
    while(cin>>n)
        solve();
}