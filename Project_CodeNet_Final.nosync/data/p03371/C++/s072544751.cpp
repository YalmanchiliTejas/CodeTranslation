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
#include <queue>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream> // std::stringstream
#include <bitset>  // std::bitset<N>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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
bool isOk(ll index, ll key,vector<ll> &a){
	
	if(a[index]>key){
		return true;
	}
	
	return false;
}

ll bin_search(ll key, vector<ll> &a){
	
	ll l=-1;
	ll r=a.size();

	while(abs(r-l)>1){
		ll mid = (l+r)/2;
		if(isOk(mid, key, a)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return r;
}

/*
//深さ優先探索
void dfs(vector<vector<ll>> &gra,vector<bool> &seen, ll v){

	seen[v]=true;

	for(auto next : gra[v]){
		if(seen[next]){
			continue;
		}

		dfs(gra,seen,next);
	}
	
}
*/

const ll MOD=1000000007;

ll min(ll a, ll b){
	if(a>=b){
		return b;
	}
	else{
		return a;
	}
}

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}


void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;
	c *= 2;
	ll x, y;
	cin >> x >> y;
	ll min = max(a * x + b * y, max(x, y) *c);
	for (ll i = 0; i <= max(x, y); i++)
	{
		ll mon = 0;
		if (x - i >= 0 && y - i >= 0)
		{
			mon = c * i + (x - i) * a + (y - i) * b;
		}
		else{
			if(x-i>=0){
				mon = c * i + (x - i) * a;
			}
			else{
				if(y-i>=0){
					mon = c * i + (y - i) * b;
				}
				else{
					mon = c * i;
				}
			}
		}
		if(min>mon){
			min = mon;
		}
	}

	cout << min << endl;
}

int main(){
	
	solve();
	
    return 0;
}