#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n,mod=1000000007;
    scanf("%d",&n);
    ll a[n];
    for (int i=0;i<n;i++)
    scanf("%lld",&a[i]);
    ll b[n];
    b[n-1]=a[n-1];
    for (int i=n-2;i>=0;i--)
    b[i]=((a[i]%mod)+(b[i+1]%mod))%mod;
    ll sum1=0LL;
    for (int i=0;i<n-1;i++)
    {
        ll val1=((a[i]%mod)*(b[i+1]%mod))%mod;
        sum1=((sum1%mod)+(val1)%mod)%mod;
    }
    printf("%lld\n",sum1);
    return 0;
}