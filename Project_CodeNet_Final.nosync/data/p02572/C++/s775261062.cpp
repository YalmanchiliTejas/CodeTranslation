#include<iostream>
#include<string>
using namespace std;
long long a[200100],sum;
int main()
{
    long long n,mod = 1e9+7;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        sum = (sum%mod + a[i]%mod)%mod;
    }
    long long ans =0;
    for(long long i=1;i<=n;i++)
    {
        sum = (sum%mod - a[i]%mod + mod)%mod;
        ans += a[i] * sum %mod;
    }
    cout << ans%mod;
    return 0;
}