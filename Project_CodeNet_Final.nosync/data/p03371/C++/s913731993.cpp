
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using ll = long long int;
using ul = unsigned long long int;
const ll LL_MAX (1LL<<60);
const ll MOD (1000000007);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

ll f (ll a, ll b, ll x, ll y)
{
    ll res;
    if (x>y) 
        res = a*abs(x-y);
    else
        res = b*abs(x-y);
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll eq1 = a*x + b*y;
    ll eq2 = 2*c*min(x,y) + f(a,b,x,y);
    ll eq3 = 2*c*max(x,y);

    vector<ll> ans({eq1, eq2, eq3});
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;

    return 0;
}
