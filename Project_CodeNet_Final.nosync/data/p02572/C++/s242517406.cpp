//g++ -std=c++14 test.cpp -o test.out
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

//https://github.com/atcoder-live/library/blob/master/mint.cpp
struct mint {
	LL x; 
	mint(LL x=0):x((x%mod+mod)%mod){}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res+=a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res-=a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res*=a;
	}
	mint pow(LL t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const {
		return pow(mod-2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res/=a;
	}
};

struct combination {
	vector<mint> fact, ifact;//factに階乗を計算、ifactはその各々に対する逆元
	combination(LL n):fact(n+1),ifact(n+1) {
		assert(n < mod);
		fact[0] = 1;
		for (LL i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
		ifact[n] = fact[n].inv();
		for (LL i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
	}
	mint operator()(LL n,LL k) {
		if (k < 0 || k > n) return 0;
		return fact[n]*ifact[k]*ifact[n-k];
	}
};

LL N;
LL A[200000];
 
mint ans = 0;

void solve(){
	mint accum = A[0];
	for(int i=1;i<N;i++){
		ans += accum*mint(A[i]);
		accum += mint(A[i]);
	}
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();
 
    cout << ans.x << endl;
    return 0;
}