#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i=x;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)
#define sp(p) cout<<setprecision(16)<<fixed<<p<<endl;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(rall(a))
#define UNIQ(a) unique(all(a))
#define UNIQNUM(a) UNIQ(a)-a.begin()
#define UNIQIT(a) a.erase(UNIQ(a), a.end());
#define VOUT(v,i) cout<<#v<<": ";for(int i=0;i<(int)v.size();i++){cout<<v[i]<<" ";}cout<<"\n";
#define vout(v) VOUT(v,z);
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define vsum(v) accumulate(all(v), 0LL)
#define MOUT(m,r,c) rep(i,r){rep(j,c){cout<<m[i][j]<<" ";}cout<<endl;}
#define mout(m) MOUT(m,m.size(),m[0].size())
#define debg(a) cout<<#a<<": "<<a<<endl;
#define show(a) for(cont &y:a){for(cont &x:y){cout<<x<<" ";}cout<<endl;}
#define digit(a) to_string(a).length();
template<class T>inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef vector<ll> V;
// const long long MOD=1000000007;
const long long INF = 1e18;
#define EPS (1e-7)
#define PI (acos(-1))
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) { a = b; return true; }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) { a = b; return true; }
    return false;
}

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1000000007> mint;
typedef vector<mint> vmint;
ostream &operator<<(ostream &o, const mint v) {  o << v.x; return o; }


// make n! and 1/n! table to calculate nCr faster.
// O(n + log mo)
vector<mint> fact, rfact;
// vector<ll> fact, rfact;
void constructFactorial(const long long n) {
    fact.resize(n);
    rfact.resize(n);
    fact[0] = rfact[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        fact[i+1] = fact[i] * (i+1);
    }
    rfact[n-1] = mint(1) / fact[n-1]; 
    // rfact[n-1] = 1.0 / fact[n-1]; 
    for (int i = n - 1; i >= 1; i--) 
        rfact[i-1] = rfact[i] * i; // ((n-1)!)^-1 = (n!)^-1 * n
}

// O(1)
// required: constructFactorial
mint nCr(const long long n, const long long r) {
// ll nCr(const long long n, const long long r) {
    if (n < 0 || r < 0) return 0;
    if (n < r) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
}

// O(k log mo) 
ll nCrNaive(const long long n, const long long k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    ll ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= (ll)n - (ll)i;
        ret /= ll(i+1);
    }
    return ret;
}

void solve_WA(string N, long long K){
    ll d=N.length();
    ll sum=0;
    sum+=(pow(9,K)*nCrNaive(d,K));
    // debg(nCrNaive(d,K));
    // debg(sum);
    if(K==1){
        sum-=('9'-N[0])*pow(9,K-1);
    }else if(K==2){
        sum-=('9'-N[0])*(d-1)*pow(9,K-1);
        sum-=('9'-N[1]);
    }else{
        sum-=('9'-N[0])*nCrNaive(d-1,K-1)*pow(9,K-1);
        sum-=('9'-N[1])*(d-2)*pow(9,K-2);
        sum-=('9'-N[2]);
    }
    cout << sum << endl;
}

void solve(string N, long long K){
    ll n=N.length();
    ll dp[n+1][K+1][2]={};
    dp[0][0][0]=1;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <=K; j++) {
            dp[i+1][j][1] += dp[i][j][1];
            if(N[i]=='0') dp[i+1][j][0] += dp[i][j][0];
            if(N[i]!='0') dp[i+1][j][1] += dp[i][j][0];
            for (ll h = 1; h <= 9; h++) {
                if(j+1<=K && N[i]==('0'+h)) dp[i+1][j+1][0] += dp[i][j][0];
                if(j+1<=K){
                    dp[i+1][j+1][1] += dp[i][j][1];
                    if('0'+h < N[i]) dp[i+1][j+1][1] += dp[i][j][0];
                }
            }
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
}

int main(){
    // long long N;
    string N;
    cin>>N;
    // scanf("%s",&N);
    long long K;
    scanf("%lld",&K);
    solve(N, K);
    return 0;
}
