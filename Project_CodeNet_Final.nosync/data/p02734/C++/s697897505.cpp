#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 998244353;

ll n, k;
ll a[3005];
ll b[3005];
ll ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    b[0] = 1;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = k; j >= 0; j--)
        {
            if(a[i] + j <= k) b[a[i] + j] += b[j], b[a[i] + j] %= M;
        }
        ans += b[k];
        ans %= M;
        b[0]++;
        b[0] %= M;
    }
    cout<<ans<<endl;
    return 0;
}
