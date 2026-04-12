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

const ll INF = 1e18;
const int MX = 100001;

int stir[3001][3001];

int N,MOD;

template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    void init () {
        fac[0] = ifac[0] = 1;
    	FOR(i,1,SZ+1) {
    	    fac[i] = i*fac[i-1] % MOD;
    	    ifac[i] = inv(fac[i]);
    	}
    }
    
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b || b < 0 || a < 0) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
    }
};

Combo<3001> C;


ll po (ll b, ll p, ll m) { return !p?1:po(b*b%m,p/2,m)*(p&1?b:1)%m; }

ll ad(ll a, ll b) { return (a+b)%MOD; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll mul(ll a, ll b) { return a*b%MOD; }


int solve(int bad) {
    int rem = N-bad;
    ll po2[bad+1]; 
    po2[0] = 1;
    po2[1] = po(2,rem,MOD);
    FOR(i,2,bad+1) po2[i] = mul(po2[i-1],po2[1]);
    ll t = 0;
    F0R(i,bad+1) {
        t = ad(t,mul(stir[bad][i],po2[i]));
        if (i) t = ad(t,mul(i,mul(stir[bad][i],po2[i-1])));
    }
    t = mul(t,po(2,po(2,rem,MOD-1),MOD));
    t = mul(t,C.fac[N]);
    t = mul(t,C.ifac[N-bad]);
    t = mul(t,C.ifac[bad]);
    return t;
} 

void genStir() {
    stir[0][0] = 1;
    FOR(i,1,3001) FOR(j,1,3001) stir[i][j] = ad(mul(j,stir[i-1][j]),stir[i-1][j-1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> MOD;
    genStir();
    C.init();
    ll ans = 0;
    F0R(i,N+1) {
        if (i&1) ans = sub(ans,solve(i));
        else ans = ad(ans,solve(i));
    }
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS