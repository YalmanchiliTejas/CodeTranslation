#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vs = vector<string>;
using pll = pair<ll, ll>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i, a, b) for(ll i=(a); i<(b); i++)
#define FORD(i, a, b) for(ll i=ll(b)-1;i>=(a);i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
    cin.sync_with_stdio(0);

    ll mod = pow(10, 9) + 7;

    ll n;
    cin >> n;
    vl a(n);
    ll sum = 0;
    FOR(i, 0, n) {
        ll tmp;
        cin >> tmp;
        tmp %= mod;
        a[i] = tmp;
        sum += tmp;
        sum %= mod;
    }
    ll end = 0;
    FOR(i, 0, n) {
        end += (a[i] * ((sum + mod - a[i]) % mod)) % mod;
        end %= mod;
    }
    if (end % 2 == 0) {
        cout << end / 2 << endl;
    } else {
        cout << ((end + mod) / 2) % mod << endl;
    }
}