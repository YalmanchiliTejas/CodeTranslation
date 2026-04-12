#pragma GCC optimize ("O3")
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
#define uint unsigned int
#define MOD 1000000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define T long long
#define mat vector<vector<T>>
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cld complex<long double>
using namespace std;

int main(){
	fast_io();
	int n;cin >> n;
	vector<ll> v(n);
	ll s = 0;
	cu(i,0,n){cin >> v[i];s += v[i];}
	ll ans = -1;
	for(ll m = s - n * (n - 1); m <= s; ++m){
		ll cnt = 0;	
		cu(i,0,n){
			cnt += (v[i] + 1 + m)/(n + 1); 
		}
		if(cnt <= m){
			ans = m;
			break;
		}
	}
	cout << ans << '\n';
}
