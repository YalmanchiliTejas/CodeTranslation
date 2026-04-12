#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,a,n) for(ll i=a;i<n;i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

const int INF = 100000000;
const ll LINF = 1e18+5;

const ll M = 998244353; // modの値

vector<ll> fac(12000000); // n! mod M
vector<ll> ifac(12000000); // k^{M-2} mod M

ll mpow(ll x, ll n){ // x^n(modM)
    ll ans = 1;
    while (n!=0) {
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n= n>>1;
    }
    return ans;
}

ll comb(ll a, ll b) { // aCb mod M
    if (a==0 && b==0) return 1;
    if (a<b || a<0) return 0;
    ll tmp = ifac[a-b] * ifac[b] % M;
    return tmp * fac[a] % M;
}

void init_comb() {
    fac[0] = 1;
    ifac[0] = 1;
    for (ll i=0;i<12000000;i++) {
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i] * mpow(i+1, M-2) % M; // k^{M-2} mod M
    }
}

int main() {
    ll N;
    cin >> N;
    init_comb();
    ll Anum = 0LL;
    REP(k,N/2+1,N+1) {
        Anum += (mpow(2, N-k) * comb(N, k)) % M;
        Anum %= M;
    }
    ll ans = (mpow(3, N) - 2 * Anum + 3*M) % M;
    cout << ans << endl;
    return 0;
}