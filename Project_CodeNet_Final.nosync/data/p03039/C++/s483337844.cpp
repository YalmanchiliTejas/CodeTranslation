#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll sq(ll x){
	return x * x % MOD;
}

ll mod_pow(ll x,ll p){
	if(p == 0)return 1;
	return ((p&1?x:1LL) * sq(mod_pow(x,p/2))) % MOD;
}

ll eval(ll n){
	return (n * n * (n + 1)/2 - n * (n + 1) * (2*n +1)/6) % MOD;
}

int main(){
	fast_io();
	ll n,m,k;
	cin >> n >> m >> k;
	vector<ll> frac(200005),inv(200005);
	frac[0] = 1;	
	inv[0] = 1;	
	fu(i,1,m*n){
		frac[i] = frac[i-1] * i % MOD;
		inv[i] = mod_pow(frac[i], MOD - 2);
	}
	ll sum = sq(m) * eval(n) + sq(n) * eval(m);
	sum %= MOD;
	ll comb = frac[n*m - 2] * inv[n*m - k] % MOD;
	comb = comb * inv[k - 2] % MOD;
	sum *= comb;
	sum %= MOD;
	cout << sum << '\n';
}
