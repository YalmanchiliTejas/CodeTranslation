#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
const ll MOD = (ll)998244353;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using vvvvector = vector<vvector<vector<t>>>;
template<class t>
using vvvvvector = vector<vvvvector<t>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

ll factorial(ll x){
	static vector<ll> memo;
	if(memo.empty()){
		int n = 1e7;
		memo.resize(n+1);
		memo[1]=1;
		repa(i, n){
			memo[i+1] = (i+1) * memo[i] % MOD;
		}
	}
	if(x<=1)return 1;
	return memo[x];
}

ll C(ll a, ll b){
	return factorial(a) * modinv(factorial(b)) % MOD * modinv(factorial(a-b)) % MOD;
}

int main(){
	ll n;
	cin >> n;
	ll ans = modpow(3, n);
	for(int i=n/2-1;i>=0;--i){
		ans -= 2 * C(n, i) * modpow(2, i) % MOD;
		ans = (ans % MOD + MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}


