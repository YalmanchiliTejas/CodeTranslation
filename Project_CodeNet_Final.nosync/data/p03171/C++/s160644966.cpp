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
ll n;
ll a[3009];
ll dp[3009][3009];
ll f(ll x, ll y){
    if(dp[x][y] != -1e18)
        return dp[x][y];
    if(x > y)
        return dp[x][y] = 0;
    return dp[x][y] = max(a[x] - f(x+1, y), a[y] - f(x, y-1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < n; ++j)
            dp[i][j] = -1e18;
    cout << f(0, n-1) << "\n";
}