//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 1000000007;

//--------------------------------------------

ll facts[200010],invs[200010];
ll powll(ll base,ll power){
    ll ans = 1;
    while (power){
        if (power&1) ans = (base*ans)%mod;
        base = (base*base)%mod;
        power >>= 1;
    }
    return ans;
}
int ni,mi,k,n;
signed main(){
    I(ni); I(mi); I(k);
    n = ni*mi;

    ll f = 1;
    facts[0] = 1;
    FOR(i,1,n+1){
        f *= i;
        f %= mod;
        facts[i] = f;
    }
    ll inv = powll(f,mod-2);
    invs[n] = inv;
    REPNS(i,n){
        inv *= i;
        inv %= mod;
        invs[i-1] = inv;
    }

    int ret = 0;
    REP(i,ni) REP(j,mi){
        int dist = 0;
        
        dist += i * (i+1) / 2 * mi;
        int negi = ni-i-1;
        dist += negi * (negi+1) / 2 * mi;
        dist += j * (j+1) / 2 * ni;
        int negj = mi-j-1;
        dist += negj * (negj+1) / 2 * ni;
        dist %= mod;

        ret = (ret + dist) % mod;
    }
    int nck = (facts[n] * invs[k]) % mod;
    nck = nck * invs[n-k] % mod;
    int n1ck1 = (facts[n-1] * invs[k-1]) % mod;
    n1ck1 = n1ck1 * invs[n-k] % mod;
    cerr << nck << " " << n1ck1 << " " << ret << endl;

    int n1inv =  powll(n-1,mod-2);
    int ninv =  powll(n,mod-2);
    
    // ret = (ret * n1ck1) % mod;
    // ret = ret * n1inv % mod;
    // cerr << ret << endl;
    ret = ret * (k-1) % mod;
    cerr << ret << endl;

    ret = (ret * n1inv) % mod;
    cerr << ret << endl;

    ret = (ret * nck) % mod;
    ret = ret * k % mod;
    ret = ret * ninv % mod;

    ret = ret * powll(2,mod-2) % mod;
    // ret = ret * powll(n+1-k, mod-2) % mod;

    cout << ret << endl;
}