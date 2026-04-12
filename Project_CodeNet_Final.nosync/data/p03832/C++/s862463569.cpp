#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define MOD 1000000007
#define MAXN 52
#define MAXH 20
#define MAXM 52
#define INF 100000000
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;

ll modpow(ll x,ll p){
	if(p == 0)return 1;
	ll y = 1;
	while(p > 1){
		if(p&1)y = x * y % MOD;
		x = x * x % MOD;
		p>>=1;
	}
	return x * y % MOD;
}

ll mul(ll x, ll y){return x * y % MOD;}

int main(){
	ll n,a,b,c,d;
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	ll knap[n+1] = {};
	knap[0] = 1;
	ll fac[n+1],inv[n+1];
	fac[0] = inv[0] = 1;
	fu(i,1,n){
		fac[i] = fac[i-1] * i % MOD;
		inv[i] = modpow(fac[i], MOD - 2);
	}
	fu(i,a,b){// fix
		fd(cur,n,0){
			fu(j,c,d){
				if(i * j + cur > n)break;
				int tar = i * j + cur;
				ll mult = mul(mul(fac[tar],modpow(inv[i],j)), mul(inv[cur],inv[j]));
				knap[tar] = (knap[tar] + mul(mult,knap[cur])) % MOD;
			}
		}
	}
	cout << knap[n] << '\n';
}

