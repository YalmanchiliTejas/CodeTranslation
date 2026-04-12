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

#define MOD 1000000007

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vl arr(n); FOR(i, 0, n) cin >> arr[i];

    vl suffix(n, 0);
    suffix[n - 1] = arr[n - 1];
    FORD(i, 0, n - 1) {
        suffix[i] = suffix[i + 1] + arr[i];
        suffix[i] %= MOD;
    }

    ll output = 0;
    FOR(i, 0, n - 1) {
        output += arr[i] * suffix[i + 1];
        output %= MOD;
    }

    cout << output << endl;
}