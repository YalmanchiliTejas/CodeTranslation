#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 998244353
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 10000005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int len;
ll res,f[MAXN],power[MAXN];

ll inv(ll a){
	ll x1 = 1, b1 = a, x2 = 0, b2 = MOD;
	while (b2) {
		ll q = b1/b2;
		b1-=q*b2, x1-=q*x2;
		swap(x1,x2);
		swap(b1,b2);
	}
	return ((x1%MOD)+MOD)%MOD;
}

ll cnk(ll n, ll k){
	if(k > n) return 0;
	ll q = (inv(f[k])*inv(f[n - k]))%MOD;
	return (f[n]*q)%MOD;
}

int main(){
	scanf("%d",&len);
	f[0] = power[0] = 1;
	for(int i=1; i<=len; i++){
		f[i] = (f[i-1]*i)%MOD;
		power[i] = (power[i-1]*2)%MOD;
	}
	res = fpow(3,len,MOD);
	for(int i=len/2+1; i<=len; i++){
		ll add = (cnk(len,i)*2)%MOD;
		add = (add*power[len-i])%MOD;
		res = (res-add+MOD)%MOD;
	}
	printf("%lld\n",res);
}