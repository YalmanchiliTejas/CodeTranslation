#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll dpall[100009][109];
ll dplim[100009][109];
ll a[100009];
ll mod = 1e9+7;
ll n, d;
string s1;
ll calc(ll x){
    x %= mod;
    if(x < 0)
        x += d;
    return x;
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> s1;

    cin >> d;

    n = s1.size();

    for(ll i = 0; i < n; ++i)
        a[i] = s1[i]-'0';
    dpall[n][0] = dplim[n][0] = 1;

    for(ll i = n-1; i >= 0; --i)
        for(ll j = 0; j < d; ++j)
            for(ll k = 0; k <= 9; ++k){
                dpall[i][j] += dpall[i+1][calc(j-k%d)];
                dpall[i][j] %= mod;
                if(k < a[i])
                    dplim[i][j] += dpall[i+1][calc(j-k%d)];
                if(k == a[i])
                    dplim[i][j] += dplim[i+1][calc(j-k%d)];
                dplim[i][j] %= mod; 
            }
    ll ans = dplim[0][0]-1;
    if(ans < 0)
        ans += mod;
    cout << ans << "\n";
}