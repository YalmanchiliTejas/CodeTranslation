/*** akshaykumar99 ***/
 
#include<bits/stdc++.h> 
using namespace std;
 
const long long MOD = 1e9+7;
const long double PI = acos(-1);
const long long N = 1e18+1;
 
typedef long long ll;
typedef long double ld;
ll binpow(ll a, ll b, ll m) 
{
    a %= m;
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return binpow(x, MOD-2, MOD);
}

ll findProductSum(vector<ll> A, ll n) 
{ 
    ll array_sum = 0; 
    for (ll i = 0; i < n; i++) 
    {
        array_sum = (array_sum + A[i]) % MOD; 
    }
    ll array_sum_square = (array_sum * array_sum) % MOD; 
    ll individual_square_sum = 0; 
    for (ll i = 0; i < n; i++) 
    {
        individual_square_sum = (individual_square_sum + A[i]*A[i] % MOD) % MOD; 
    }
    ll ans = (array_sum_square - individual_square_sum + MOD) * inv(2) % MOD;
    return ans; 
}

void test_case()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++)
    {
    	cin >> v[i];
    }
    cout << findProductSum(v, n) << '\n';

}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    ll tc=1;
    // cin>>tc;
    while(tc--)
        test_case();
    return 0;
}
