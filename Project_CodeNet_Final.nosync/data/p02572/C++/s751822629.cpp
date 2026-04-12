#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
#define FOR(i, s, n) for (ll i = (s); i < (n); ++i)
#define FORALL(i, n) for (ll i = 0; i < (n); ++i)
#define MOD 1000000007
#define ff first
#define ss second
#define pll pair<long long, long long>
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(false)
#define countbits(x) __builtin_popcount(x)
#define pb(x) push_back((x))
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define print(x) cout << x << endl
#define debug print("reaching\n")
#define mll map<ll,ll>
#define lsb(i) i&(-i)
#define printv(x) \
	FORALL(i, x.size()) \
	{ \
		cout << x[i] << ' '; \
	} \
	cout << endl \
;
#define printm(m) \
	for(auto i: m){\
		cout<<i.ff<<' '<<i.ss<<endl; \
	}\
;
// vector<map<ll,ll>> m(2);
long long binpow(long long a, long long b) {
	if(b<=0) return 1;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



template <typename T>
T extGcd(T a, T b, T &x, T &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m)
{
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}


int main()
{
	fast;
	// cin.tie(0);
	// cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t=1;
	// cin>>t;
	ll tot=t;
	while(t--){
		ll n;
		cin>>n;
		vll v(n);
		FORALL(i,n){
			cin>>v[i];
		}
		ll ans = 0;
		ll odd = 0;
		ll even = 0;
		FORALL(i,n){
			if(i%2==0){
				even += v[i];
				even%=MOD;
			}
			else{
				odd +=v[i];
				odd %=MOD;
			}
		}
		ans = (odd * even)%MOD;
		ans += MOD;
		ans %=MOD;
		for(int i = 0; i < n; i ++){
			if(i%2 == 0){
				even -= v[i];
				even +=MOD;
				even%=MOD;
				ans = (ans + (even * v[i])%MOD)%MOD;
			}
			if(i%2){
				odd -= v[i];
				odd +=MOD;
				odd%=MOD;
				ans = (ans + (odd * v[i])%MOD)%MOD;
			}
		}
		print(ans);
	}
	return 0;
}
