#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
// #include<unordered_map>
#include<set>
// #include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
#define ln() cout << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007; // 998244353 , 1000000007
const ll m4x[4] = { 1,0,-1,0 };
const ll m4y[4] = { 0,1,0,-1 };
const ll m8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const ll m8y[8] = { 0,1,1,1,0,-1,-1,-1 };
const ll m9x[9] = { 1,1,0,-1,-1,-1,0,1,0 };
const ll m9y[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct edge {
	ll from, to, cost;
	bool operator<(const edge& right) const {
		return cost < right.cost;
	}
	bool operator>(const edge& right) const {
		return cost > right.cost;
	}
};

struct point {
	ll x, y, idx;
	bool operator<(const point& right) const {
		return x == right.x ? y < right.y : x < right.x;
	}
	bool operator>(const point& right) const {
		return x == right.x ? y > right.y : x > right.x;
	}
};

ll bisect_left(ll arr[], ll arr_size, ll key) {
	return distance(arr, lower_bound(arr, arr + arr_size, key));
}

ll bisect_left(vector<ll> vc, ll key) {
	return lower_bound(vc.begin(), vc.end(), key) - vc.begin();
}

ll pow_mod(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a % MOD;
	ll ret = pow_mod(a, x / 2);
	if (x % 2 == 0) ret = (ret*ret) % MOD;
	else ret = ((a % MOD) * ((ret*ret) % MOD)) % MOD;
	return ret;
}

void build_mod_fact(ll arr[], ll n) {
	arr[0] = 1;
	repi(i, 1, n + 1) {
		arr[i] = (arr[i - 1] * i) % MOD;
	}
	return;
}

void build_mod_fact_inv(ll arr_fact[], ll arr_fact_inv[], ll n) {
	arr_fact_inv[n] = pow_mod(arr_fact[n], MOD - 2);
	repd(i, n - 1, -1) {
		arr_fact_inv[i] = (arr_fact_inv[i + 1] * (i + 1)) % MOD;
	}
	return;
}

ll comb_mod(ll n, ll r, ll arr_fact[], ll arr_fact_inv[]) {
	return (((arr_fact[n] * arr_fact_inv[n - r]) % MOD) * arr_fact_inv[r]) % MOD;
}

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}


///////////////////////////////////////////////////////////////////////////////////////

ll n, x, ans;
ll sBP[100], sP[100];

void calc_s(ll N) {
	sBP[0] = 1, sP[0] = 1;
	repi(i, 1, N + 1) {
		sBP[i] = sBP[i - 1] * 2 + 3;
		sP[i] = sP[i - 1] * 2 + 1;
	}
	return;
}

int main() {
	cin >> n >> x;

	calc_s(n);
	repd(i, n, -1) {
		if (sBP[i] == x) {
			ans += sP[i];
			x -= sBP[i];
		}
		else if (sBP[i] / 2 < x) {
			ans += sP[i - 1] + 1;
			x -= sBP[i - 1] + 2;
		}
		else {
			x -= 1;
		}
	}
	cout << ans << endl;

	return 0;
}
