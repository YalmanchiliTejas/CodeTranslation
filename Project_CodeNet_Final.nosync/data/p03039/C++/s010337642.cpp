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

const ll N_MAX = 300005;

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

ll Combination(ll C, ll D){
    if(C<D||C<1) return 0;
    return fac[C]*(finv[D]*finv[C-D]%mod)%mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, K;
    cin >> N >> M >> K;

    ll res = 0;
   	for(int k=1;k<M;k++){
    	ll tmp = 1;
    	tmp *= (M-k);
    	tmp %= mod;
    	tmp *= N;
    	tmp %= mod;
    	tmp *= N;
    	tmp %= mod;
    	res += (tmp * k % mod);
    	res %= mod;
    }
    for(int k=1;k<N;k++){
    	ll tmp = 1;
    	tmp *= (N-k);
    	tmp %= mod;
    	tmp *= M;
    	tmp %= mod;
    	tmp *= M;
    	tmp %= mod;
    	res += (tmp * k % mod);
    	res %= mod;
    }
    make();
    res *= Combination(N*M-2, K-2);
    res %= mod;
    cout << res << endl;
    return 0;
}