/*COMPETITIVE PROGRAMMING C++ TEMPLATE */

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 1000000007

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> pref(n);

    pref[0] = a[0];

    for(int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
        pref[i] %= MOD;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ll diff = pref[n - 1] - pref[i];
        diff %= MOD;
        diff += MOD;
        diff %= MOD;
        
        ans += (a[i] * diff) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    //cin >> T;
    
    while (T--)
    {
        solve();
    }
    
    return 0;
}


