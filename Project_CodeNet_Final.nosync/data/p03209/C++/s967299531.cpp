#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define sz(s) (int)s.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define for1(i,n) for(int i=1;i<=(int)n;i++)
#define ford(i, b, a) for (int i = (int)(b); i >= a; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
const ll N = (ll)1e5+77;
const ll inf = (ll) 1e16+7;
const ll mod = (ll) 1e8;
const ld pi = acos(-1);

ll n, m, k;
pll layer[55];

pll memo(ll l) {
    if(l==0) return {1,1};
    if (layer[l].first != -1) return layer[l];
    pll tmp, ret = {1, 0};
    tmp = memo(l - 1);
    ret.first += tmp.first;
    ret.second += tmp.second;
    ret.first += 1;
    ret.second += 1;
    tmp = memo(l - 1);
    ret.first += tmp.first;
    ret.second += tmp.second;
    ret.first += 1;
    return layer[l] = ret;
}

ll solve(ll l, ll x) {
    if(l == 0) return 1;
    if (x <= 1) return 0;
    ll ret = 0;
    if (x <= layer[l - 1].first + 1) {
        ret += solve(l - 1, x - 1);
    } else if (x == layer[l - 1].first + 2) {
        ret += layer[l - 1].second + 1;
    } else if (x <= 2 * layer[l - 1].first + 2) {
        ret += layer[l - 1].second + 1 + solve(l - 1, x - layer[l - 1].first - 2);
    } else if (x == 2 * layer[l - 1].first + 3) {
        ret += 2 * layer[l - 1].second + 1;
    }
    return ret;
}

int main() {
    fast;
    cin >> n >> k;
    forn(i, 54) layer[i] = {-1, -1};
    layer[0] = {1, 1};
    memo(n);
    forn(i, 54) {
//        cout<<layer[i].first<<" "<<layer[i].second<<endl;
    }
    cout << solve(n, k) << endl;
    return 0;
}