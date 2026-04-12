#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define maxs(x,y) x = max(x, y)
#define mins(x,y) x = min(x, y)
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y;
    cin >> x >> y;
    
    ll ans = a*x + b*y;
    // cout << ans << endl;
    
    for(ll i = 0; i/2 < max(x, y)+1; i+=2) {
        ll temp = a*(max(0LL,x-i/2)) + b*(max(0LL, y-i/2)) + c*i;
        // cout << temp << " " << x-i/2 << " " << y-i/2 << " " << i << endl;
        ans = min(ans, temp);
    }

    cout << ans << endl;
    return 0;
}