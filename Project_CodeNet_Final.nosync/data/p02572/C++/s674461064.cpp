#include <bits/stdc++.h>

using namespace std;
#define  ll  long long
#define f first
#define s second
#define matrix vector<vector<ll>>
#define zero(n,m) matrix(n , vector<ll>(m,0))
#define one(n,m) matrix(n , vector<ll>(m,1))
#define pii pair<ll,ll>
const int N = 2e5+5;

ll n , a[N] , sum , rem , ans , tmp , mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        sum = (sum+a[i])%mod;
    }

    for(int i=1; i<=n; i++)
    {
        sum = (sum-a[i]%mod) , sum = (sum+mod)%mod;
        tmp = ( (sum) * (a[i]%mod) )%mod;
        ans += tmp;
        ans %= mod;

    }

    cout << ans << '\n';

    return 0;
}

