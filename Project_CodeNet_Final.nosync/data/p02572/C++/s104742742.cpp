#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    ll n,sum=0,sum_a=0;
    cin >> n;
    vector<ll> a(n);
    const ll mod=1000000007;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum_a+=a[i];
    }
//    sum_a%=mod;
    for(int i=0;i<n;i++)
    {
        sum_a-=a[i];
        sum=(sum%mod)+(sum_a%mod)*(a[i]%mod);
        sum%=mod;
    }
    cout << sum << endl;
    return 0;
}
