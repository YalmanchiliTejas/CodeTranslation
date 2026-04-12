#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll qp ( ll a , ll b )
{
    ll ans = 1;
    while ( b )
	{
        if ( b & 1 )
		   ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ans;
    
}

const int N = 2e5 + 10;
ll fac[N];

ll C ( ll a , ll b )
{
    ll ans = fac[a] * qp ( fac[b] , MOD - 2 ) % MOD;
    ans = ans * qp ( ( fac[a-b] + MOD ) % MOD , MOD - 2 ) % MOD;
    
    return ans;
    
}

ll n,m,k,ans;

int main ()
{
    fac[0] = 1;
    for ( int i = 1 ; i < N ; ++ i )
	    fac[i] = fac[i - 1] * i % MOD;
    cin >> n >> m >> k;
    ans = C ( n * m , k ) * C ( k , 2 ) % MOD * qp ( 3 , MOD - 2 ) % MOD;
    ans = ans * ( n + m ) % MOD;
    ans %= MOD;
    
    cout << ans << '\n';
    
    return 0;
    
}