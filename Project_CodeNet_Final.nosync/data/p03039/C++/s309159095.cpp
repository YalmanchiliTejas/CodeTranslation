#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; ++i)
#define REPR(i,n) for(int i = n; i >= 0; --i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define p(s) cout << (s) << endl
#define p2(s,t) cout << (s) << " " << (t) << endl 
#define ALL(v) (v).begin(), (v).end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;

static const ll MOD  = 1e9 + 7;
static const ll inf  = 1e18;
const int MAX = 510000;

static const int White = 0;
static const int Gray = 1;
static const int Black = 2;

void pvector(vector<int> A){
    cout << "[vector]";
    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
// const ll MOD=1000000007ll;


ll fact[MAX], fact_inv[MAX];

//繰り返し二乗法
ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll comb(ll n, ll r){
    return (fact[n] * fact_inv[r]) % MOD * fact_inv[n-r] % MOD;
}

int main(){
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    int N = 200001;
    fact[0] = 1;
    //階乗計算(O(n))
    REP(i, N) fact[i+1] = fact[i] * (i+1) % MOD;
    fact_inv[N] = power(fact[N], MOD - 2);
    //逆元計算(O(logp + n))
    FORR(i, 0, N) fact_inv[i] = fact_inv[i+1] * (i+1) % MOD;
    //あとはconb(n,r)に値を突っ込めば良い

    for(ll d = 1; d < n; d++){
        ans += d * comb(n*m-2, k-2) % MOD * (( n - d ) * m * m) % MOD;
        ans %= MOD;
    }
    for(ll d = 1; d < m; d++){
        ans += d * ( comb(n*m-2,k-2) % MOD) * ((( m - d ) * n * n ) % MOD);
        ans %= MOD;
    }
    p(ans);
    
}