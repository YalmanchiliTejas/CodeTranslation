#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll total = 0;
    total += min(a + b, 2 * c) * min(x, y);
    ll _x = x - min(x, y), _y = y - min(x, y);
    total += min(a, 2 * c) * _x + min(b, 2 * c) * _y;
    cout << total << endl;
    return 0;
}