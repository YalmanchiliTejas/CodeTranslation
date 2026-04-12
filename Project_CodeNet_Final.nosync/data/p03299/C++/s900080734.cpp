
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;


ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

ll ad(ll a, ll b) { return (a+b)%MOD; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll mul(ll a, ll b) { return a*b%MOD; }
ll divi(ll a, ll b) { return mul(a,inv(b)); }

int N;
vi h(N);

pi get(vi x);

pi process(vi& cur) {
    for (int& i: cur) i --;
    pi z = get(cur);
    cur.clear();
    return z;
}

pi solve(vi x) {
    vpi ret;
    vi cur;
    ll a = 2, b = 1;
    for (int i: x) {
        if (i > 1) cur.pb(i);
        else {
            b = mul(2,b);
            if (sz(cur)) {
                ret.pb(process(cur));
                assert(sz(cur) == 0);
            }
        }
    }
    if (sz(cur)) ret.pb(process(cur));
    
    // dp[x][1] = 2*dp[a][1]*dp[b][1]*...
    // dp[x][0] = 2^rem*(dp[a][0]+dp[a][1])*(dp[b][0]*dp[b][1])*... is this correct?
    for (auto t: ret) {
        a = mul(a,t.f);
        b = mul(b,ad(t.f,t.s));
    }
    // for (int i: x) cout << i << " ";
    // cout << "| " << a << " " << b << "\n";
    return {a,b};
}

pi transform(pi t, int mn) {
    // cout << "OOPS\n";
    int ne = mul(po(2,mn-1),t.f);
    t.s = ad(t.s,sub(ne,t.f));
    t.f = ne;
    return t;
    // dp[x][1] = dp[a][1];
    // dp[x][0] = dp[a][0]+dp[a][1]
    // repeat mn-1 times
}

pi get(vi x) {
    int mn = MOD; F0R(i,sz(x)) mn = min(mn,x[i]);
    F0R(i,sz(x)) x[i] -= (mn-1);
    /*for (int i: x) cout << i << " ";
    cout << "\n";
    cout << mn << "\n";
    exit(0);*/
    pi t = solve(x);
    return transform(t,mn);
}

int main() {
    // cout << brute({1,2,})
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; h.resize(N);
    F0R(i,N) {
        // h[i] = rand() % 1000000000+1;
        cin >> h[i];
    }
    cout << get(h).s;
    // dp[x][1] = 2*(dp[a][1]*dp[b][1]*dp[c][1]*...)
    // dp[x][0] = (dp[a][0]+2*dp[a][1])*(dp[b][0]+2*dp[b][1])*...*2^stuff-dp[x][1];
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/