#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

ll dp[1005][1005] = {};

const ll N_MAX = 100005;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];
void make(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}

ll Combination(ll C, ll D){
    if(C<D||C<1) return 0;
    return fac[C]*(finv[D]*finv[C-D]%mod)%mod;
}

ll powLL(ll a, ll n){
    ll res = 1;
    while(n>0){
        if(n&1){
            res *= a;
            res %= mod;
        }
        a = a*a;
        a %= mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll f(ll G, ll k){
	ll bunshi = fac[G*k]%mod;
	ll bunbo = fac[k]%mod;
	bunbo *= powLL(fac[G], k);
	bunbo %= mod;
	return (bunshi * modinv(bunbo, mod)) % mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    make();

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    dp[0][0] = 1;
    REP(i, B-A+1){
    	ll G = A+i;
    	REP(j, N+1){
    		dp[i+1][j] += dp[i][j];
    		dp[i+1][j] %= mod;
    		for(int k=C;k<=D;k++){
    			if(j+G*k>N) break;
    			dp[i+1][j+G*k] += (Combination(N-j, G*k)*(dp[i][j] * f(G, k)%mod))%mod;
    			//dp[i+1][j+G*k] += (Combination(N-j, G*k)*dp[i][j])%mod * f(G, k) %mod;
    			dp[i+1][j*G*k] %= mod;
    		}
    	}
    }
    cout << dp[B-A+1][N] << endl;

    /*
    REP(i,B-A+2){
    	REP(j, 10){
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    */
    return 0;
}