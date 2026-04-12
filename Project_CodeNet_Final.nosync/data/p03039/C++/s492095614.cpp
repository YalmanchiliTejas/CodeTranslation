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

ll fact[200010];

ll powI(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = powI(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll choose(ll A, ll B) {
    ll ans = fact[A];
    ans = fact[A] * powI(fact[B], MOD-2); ans = ans % MOD;
    ans = ans * powI((fact[A-B] + MOD) % MOD, MOD-2); ans = ans % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    FOR(i, 1, 200010) {
        fact[i] = fact[i-1] * i; fact[i] = fact[i] % MOD;
    }

    ll N, M, K; cin >> N >> M >> K;

    ll ans = choose(N*M, K); ans = ans * choose(K, 2); ans = ans % MOD;
    ans = ans * (N+M);
    ans = ans % MOD; ans = ans * powI(3, MOD-2); ans = ans % MOD;
    cout << ans << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343