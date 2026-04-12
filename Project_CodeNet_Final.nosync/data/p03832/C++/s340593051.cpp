#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}


#define N 1010

ll inv[N], fact[N], ifact[N];
 
void init_fact(ll n = N){
    inv[1] = 1;
    for(int i = 2; i < n;i++) inv[i] = inv[mod%i] * (mod - mod/i) % mod;
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < n; i++){
		fact[i] = (fact[i-1]*i)%mod;
		ifact[i]=(ifact[i-1]*inv[i])%mod;
	}
}

ll comb(ll a, ll b){
	return fact[a+b]*ifact[a]%mod*ifact[b]%mod;
}

ll comb_nk(ll n, ll k){
	return comb(n-k, k);
}

ll lcm(ll a, ll b){
    return a/__gcd(a, b)*b;
}

ll lambda(ll m){
    ll res = 1;
    if(m%8==0) m /= 2;
    for(ll i = 2; i*i <= m; i++){
        if(!(m%i)){
            ll r = i-1;
            m /= i;
            while(!(m%i)){
                m /= i;
                r *= i;
            }
            res = lcm(res, r);
        }
    }
    if(m>1) res = lcm(res, m-1);
    return res;
}

ll pow_mod(ll a, ll r, ll m){
	ll x = 1;
	while(r){
		if(r&1) (x*=a)%=m;
		(a*=a)%=m;
		r>>=1;
	}
	return x;
}

ll n, a, b, c, d, dp[N];

int main(){
	init_fact();
	cin>>n>>a>>b>>c>>d;
	dp[0] = fact[n];
	for(ll i = a; i <= b; i++){
		for(ll k = n; k >= i*c; k--){
			for(ll j = c, x = pow_mod(ifact[i], c, mod); j <= d; j++,x=x*ifact[i]%mod){
				if(k-i*j<0) break;
				dp[k] = (dp[k]+dp[k-i*j]*x%mod*ifact[j])%mod;
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
