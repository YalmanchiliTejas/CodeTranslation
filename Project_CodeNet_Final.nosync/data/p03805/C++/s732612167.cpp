#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <limits>
#include <set>
#include <map>
#include <type_traits>
#include <cstdint>

typedef long long ll;

using namespace std;

//素因数分解
void factoring(ll n, map<ll, ll>& mp) {
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}
	if (n != 1) mp[n]++;
}

//絶対値
template<class T, class U = std::make_unsigned_t<T>>
U SafeAbs( T x ) {
    return x < 0 ? -static_cast<uintmax_t>(x) : x;
}

//最大・最小
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//xのn乗
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
//xの逆元
ll mod_inv(ll x, ll mod) {//O(log(mod))
    return mod_pow(x, mod - 2, mod);
}

//nCr
ll ncr(ll n, ll r, ll mod){
	ll res=1;
	ll num=1,den=1;
	for(ll i=n;i>=n-r+1;i--){
		(den*=i)%=mod;
	}
	for(ll i=1;i<=r;i++){
		(num*=i)%=mod;
	}
	
	res=den*mod_inv(num,mod);

	return res%mod;
}


//二分探索
bool isOk(ll index, ll key,vector<ll> &a, bool g){
	if(g){
		if(a[index]<key){
			return true;
		}
	}
	else{
		if(a[index]>key){
			return true;
		}
	}
	return false;
}

ll bin_search(ll key, vector<ll> &a, bool g){
	
	ll l=-1;
	ll r=a.size();

	if(g){
		l=a.size();
		r=-1;
	}

	while(abs(r-l)>1){
		ll mid = (l+r)/2;
		if(isOk(mid, key, a, g)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return r;
}

ll ans=0;
ll n,m;

//深さ優先探索
void dfs(vector<vector<ll>> &gra, ll v, vector<ll> seen){

	seen.push_back(v);

	if(seen.size()==n){
		ans++;
		return;
	}

	for(auto next: gra[v]){
		bool flag=false;
		for(auto i : seen){
			if(next==i){
				flag=true;
			}
		}
		if(flag){
			continue;
		}
		dfs(gra,next,seen);
	}
}


void solve(){
	
	cin>>n>>m;

	vector<vector<ll>> gra(n);
	for(ll j=0;j<m;j++){
		ll a,b;
		cin>>a>>b;
		a--;
		b--;

		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	vector<ll> seen;

	dfs(gra,0,seen);

	cout<<ans<<endl;
	
}

int main(){
	
	solve();
	
    return 0;
}
