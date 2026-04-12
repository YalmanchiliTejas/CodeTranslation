#include <bits/stdc++.h>
 
using namespace std;
 
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int
// #define int ll
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define pb push_back
#define B begin()
#define E end()
#define sz(A) (ll)(A).size()
#define F first
#define S second
#define loop(z, v) for (auto &z : v)
#define sp << ' ' <<
#define sps << ' '
#define nl "\n"
// #define nl endl
#define fat 1000000007
// #define fat 998244353
#define PI_2 1.57079632679489661923

ll power(ll base, ll exp, ll mod) // O(logn) time
{
    ll ans=1LL;
    while(exp){
        if(exp&1LL) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exp>>=1LL;
    }
    return ans%mod;
}

int main() {
    ll tt = 1, n, m, l, r, c, i, j, k, w, x, y;
    boost;
    
    // cin >> tt;
    ll ans = 1001;

    for(int _ = 1; _ <= tt; _++) {
        // cout << "Case #" << _ << ": ";
        cin >> n;
        ans = 0;
        ll sum = 0, sq = 0;
        
        for(i = 0; i < n; i++){
            cin >> x;

            sum += x;
            sum %= fat;

            sq += x*x;
            sq %= fat;
        }

        ans = ((sum*sum - sq + fat)%fat)*power(2, fat - 2, fat);
        cout << ans%fat << nl;
    }
}