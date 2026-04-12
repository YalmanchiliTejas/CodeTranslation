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

ll dp[1010][1010];
ll N, A, B, C, D;

const ll N_MAX = 1000005;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];
void make(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll) i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
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

ll Combination(ll C, ll D){
    if(C<D||C<1) return 0;
    return fac[C]*(finv[D]*finv[C-D]%mod)%mod;
}

ll pows(ll x, ll k){
	if(k == 0) return 1;
	ll res = pows(x, k/2);
	if(k%2 == 0){
		return (res * res) % mod;
	}else{
		return res * res % mod * x % mod;
	}
}

ll rec(ll nok, ll val){
	if(dp[nok][val] >= 0) return dp[nok][val];
	if(val == B+1){
		if(nok == 0) return 1;
		else return 0;
	}
	ll res = 0;
	res += rec(nok, val+1);
	res %= mod;
	for(int i=C;i<=min((nok/val), D);i++){
		if(nok - val*i < 0) continue;
		ll tmp = rec(nok - val*i, val+1);
		tmp *= Combination(nok, nok - val*i);
		tmp %= mod;
		ll ue = fac[val*i];
		ll shita = modinv(fac[val], mod);
		shita = pows(shita, i);
		shita *= modinv(fac[i], mod);
		shita %= mod;
		ue *= shita;
		ue %= mod;
		tmp *= ue;
		tmp %= mod;
		res += tmp;
		res %= mod;
	}
	dp[nok][val] = res;
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B >> C >> D;
    make();

    REP(i, 1010)REP(j, 1010) dp[i][j] = -1;

    cout << rec(N, A) << endl;
    return 0;
}