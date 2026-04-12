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

string sn;
int k;
ll powll(ll base,ll power){
    ll ans = 1;
    while (power){
        if (power&1) ans = (base*ans)%mod;
        base = (base*base)%mod;
        power >>= 1;
    }
    return ans;
}
ll facts[100010],invs[100010];

int ncr(int ni, int ri){
    return ni < ri ? 0 : facts[ni] * invs[ri] % mod * invs[ni-ri] % mod;
}
signed main(){
    int n = 500;
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

    cin >> sn;
    cin >> k;
    int count = 0;
    for (auto c : sn) count += c != '0';
    int l = sz(sn);
    int ret = count >= k;
    REP(i,l){
        if (!k) break;
        if (sn[i] == '0') continue;
        ret += ncr(l-i-1,k) * powll(9,k);
        cerr << ret << endl;

        ret += (sn[i] - '1') * ncr(l-i-1,k-1) * powll(9,k-1);
        cerr << ret << endl;
        k--;
    }

    cout << ret << endl;
}
