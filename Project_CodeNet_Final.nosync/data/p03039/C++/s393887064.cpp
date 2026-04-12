#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(ll I = int((B)-1); I >= int(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll mod=1e9+7;


class comb{
	vector<ll> f,fr;
	ll MOD;
	public:
	//a^(p-1) = 1 (mod p)(p->Prime numbers)
	//a^(p-2) = a^(-1)
	ll calc(ll a,ll b,ll p){//a^(b) mod p   
		if(b==0)return 1;
		ll y = calc(a,b/2,p);y=(y*y)%p;
		if(b & 1) y = (y * a) % p;
		return y;
	}
	void init(ll n,ll mod){//input max_n
		MOD = mod;
		f.resize(n+1);
		fr.resize(n+1);
		f[0]=fr[0]=1;
		for(ll i=1;i<n+1;i++){
			f[i] = (f[i-1] * i) % mod;
			fr[i] = calc(f[i],mod-2,mod);
		}
	}
	ll nCr(ll n,ll r){
		return f[n] * fr[r] % MOD * fr[n-r] % MOD;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N,M,K;
	cin >> N >> M >> K;
	comb co;
	co.init(N*M,mod);
	cout << (N+M)*co.nCr(K,2)%mod*co.nCr(N*M,K)%mod*co.calc(3,mod-2,mod)%mod << endl;
}
