//This template was last modified on 1/20/2020.
//Define many functions and words.
//The functions I have defined start with a capital letter.
#include <bits/stdc++.h>
using namespace std;
//C++ words.
#define MOD 1000000007 //998244353
typedef long long ll;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vl> matrix;//A(n, vl(m));
typedef vector<string> vs;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef vector<bool> vb;
typedef map<ll,ll> mapl;
typedef priority_queue<ll> pque;
#define nl "\n"s
#define rep(i,n) for(ll i=0LL; i<(n); i++)
#define INF 1001001001001001001
#define PI 3.14159265358979323846
#define SP << " "s <<
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define All(V) V.begin(),V.end()
#define Sortup(V) sort(All(V))
#define Sortdown(V) sort(V.rbegin(), V.rend())
#define Atleast(key, V) lower_bound(All(V), key)
#define Largerthan(key, V) upper_bound(All(V), key)

ll IN(){ll x; cin>>x; return x;}
void VIN(vl &x){rep(i, x.size()) cin>>x[i];}
#define endYes do{cout << "Yes" << nl; return 0;}while(0)
#define endYES do{cout << "YES" << nl; return 0;}while(0)
#define endNo  do{cout << "No" << nl; return 0;}while(0)
#define endNO  do{cout << "NO" << nl; return 0;}while(0)
#define endS(str) do{cout << str << nl; return 0;}while(0)


//Mathmatical functions.
template<class T>bool Chmax(T &a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool Chmin(T &a, T b){if(a>b){a=b;return 1;}return 0;}
template<class T>double Dist(T x,T y,T X,T Y){return sqrt( (x-X)*(x-X)+(y-Y)*(y-Y) );}
bool Bit(ll subset, ll Rsift){ return ((subset)>>(Rsift))&1; }
ll Gcd(ll a,ll b){ return b?Gcd(b,a%b):abs(a); }
ll Lcm(ll A,ll B){ return A/Gcd(A,B)*B; }
ll Lpow(ll e,ll x){ll res=1LL;while(x){if(x&1)res*=e;e*=e;x/=2;}return res;}
ll Pow(ll e,ll x){ll res=1LL;while(x){if(x&1)res=(1LL*res*e)%MOD;e=(1LL*e*e)%MOD;x/=2;}return res;}
void Add(ll &a,ll &b){a+=b; while(a>=MOD)a-=MOD;while(a<0)a+=MOD;}
void Mul(ll &a,ll &b){ a=1LL*a*b%MOD; }
void CumuSum(vl &A){rep(i,A.size())if(i)A[i]+=A[i-1];}
void Eratos_prime(vb &is_prime){//1-indexed
    ll N=is_prime.size();
    rep(i, N) is_prime.at(i) = true;
    is_prime.at(0) = is_prime.at(1) = false;
    for(ll i=2; i*i<=N; i++) if(is_prime.at(i)) {
        for(ll j=i+i; j<=N; j+=i) is_prime.at(j) = false;
    }
}
void Primefact(ll N, mapl &elem){
    for(ll i=2; i*i<=N; i++) {
        while(N%i==0) {
            elem[i]++;
            N /= i;
        }
    }
    if(N>1) elem[N]++;
}

/*
//Constraints 1<=k<=n<10^7  and  MOD is prime  and MOD>n
const ll MAX=1001001;
vl fac(MAX), finv(MAX), inv(MAX);
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
//Combination
ll COM(ll n, ll k){
    if (n<k or n<0 or k<0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
*/

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// solution comes here


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N=IN(), M=IN();
    if(N==M) endYes;
    endNo;
}