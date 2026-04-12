#include <bits/stdc++.h>

using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


#define f first
#define s second
#define db long double
#define pb push_back
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 998244353;
const int MAX = 1e7+7;
const db eps = 1e-13;


ll f[MAX];
ll invf[MAX];
ll ans;

ll exp( ll a , ll b ) {
    ll res = 1;
    while( b ) {

        if( b%2 ) {
            res = ( res * a ) % mod;
        }
        a = ( a * a ) % mod;
        b /= 2ll;

    }

    return res;
}

void initFact() {
    f[0] = 1;
    for( int i = 1 ; i < MAX ; i++ )
        f[i] = f[i-1] * i % mod;

    invf[MAX-1] = exp( f[MAX-1] , mod-2 );
    for( int i = MAX-2 ; i >= 0 ; i-- ) {

        invf[i] = invf[i+1] * (i+1) % mod;

    }
}

ll combination( ll a , ll b ) {
    return f[a] * invf[a-b] % mod * invf[b] % mod;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cout<<setprecision(0)<<fixed;

    initFact();

    int n;cin>>n;

    ans = exp(3 , n);

    vi p2(n+1,1);
    for( int i = 1 ; i <= n ; i++ )
        p2[i] = p2[i-1] * 2 % mod;

    for( int i = (n/2+1) ; i <= n ; i++ ) {
        ans -= ( combination(n , i) * p2[n-i] * 2 ) % mod;
        ans += mod;
        ans %= mod;
    }

    cout<<ans<<"\n";

}
