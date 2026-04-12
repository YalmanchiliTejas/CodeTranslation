#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

//繰り返し二乗法
template <typename T>
T doubling(T a, T p) {
	if (p == 0)return 1;//出口
	if (p % 2 == 0) {//pを半分にしていく
		T half = doubling<T>(a, p / 2);
		return half % mod * half % mod;
	}
	else {//pが奇数ならpを偶数にする
		return a * doubling<T>(a, p - 1) % mod;
	}
}

//combination その2(逆元) O(nlonP):PはmodP
template<typename T>
T combination(T n, T r) {
	if (r > n - r)return combination<T>(n, n - r);
	T mul = 1;
	T div = 1;
	for (unsigned long long int i = 0; i < r; i++) {
		mul *= n - i;
		div *= i + 1;
		mul %= mod;
		div %= mod;
	}
	//逆元
	T ans = mul * doubling(div, mod - 2) % mod;//a^(-1)=a~(p-2) (mod p)
	return ans;
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll cmb = combination<ll>(n * m - 2, k - 2);//選ぶ2点を固定したときの残りの点の選び方
	ll ans = 0;
	rep(x, m) {
		ans += x * (m - x) * n * n % mod;
		ans %= mod;
	}
	rep(y, n) {
		ans += y * (n - y) * m * m % mod;
		ans %= mod;
	}
	cout << ans * cmb % mod << endl;
}