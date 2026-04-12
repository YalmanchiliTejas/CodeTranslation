#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
ll n, m, k;
ll fac[MN];

pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = gcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues

ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, MOD);

    res.f = (res.f+MOD)%MOD;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}

ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}

ll c2(ll x){
    return (x*(x-1)/2)%MOD;
}

void getFacs(){
    fac[0] = 1;
    FOR(i, 1, MN-1){
        fac[i] = (fac[i-1]*i)%MOD;
    }
}

ll choose(ll a, ll b){
    ll c = a-b;
    if(c < 0){
        cout << "ur bad\n";
        exit(0);
    }

    ll num = fac[a];
    ll denom = (fac[b]*fac[c])%MOD;

    //cout << "num " << num << " denom " << denom << "\n";

    return modDiv(num, denom);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getFacs();

    cin >> n >> m >> k;
    
    ll smx = 0;
    FOR(i, 1, n-1){
        ll nw = n-i;
        smx = (smx+i*nw)%MOD;
    }

    ll smy = 0;
    FOR(i, 1, m-1){
        ll nw = m-i;
        smy = (smy+i*nw)%MOD;
    }

    ll nw = c2(n*m);
    ll tsx = ((smx*m)%MOD*m)%MOD;
    ll tsy = ((smy*n)%MOD*n)%MOD;

    //cout << smx << " " << smy << "\n";

    ll tot = (tsx+tsy)%MOD;

    ll xpv = modDiv(tot, nw);
    ll ch = choose(n*m, k);
    ll ch2 = choose(k, 2);
    ll res = ((xpv*ch)%MOD*ch2)%MOD;

    //cout << tot << " " << xpv << " " << ch << "\n";

    cout << res << "\n";

    return 0;
}
