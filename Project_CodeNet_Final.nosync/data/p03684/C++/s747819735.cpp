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
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
#define ln() cout << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007;
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
	if (x == 1) return a;
	ll ret = pow_mod(a, x / 2);
	if (x % 2 == 0) ret = (ret*ret) % MOD;
	else ret = (a * ((ret*ret) % MOD)) % MOD;
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


///////////////////////////////////////////////////////////////////////////////////////

struct p {
	ll x, idx;
	bool operator<(const p& right) const {
		return x < right.x;
	}
};

struct e {
	ll to, cost;
	bool operator<(const e& right) const {
		return cost < right.cost;
	}
	bool operator>(const e& right) const {
		return cost > right.cost;
	}
};

ll N;
bool used_idx[MAX_10p5];
p xy[2][MAX_10p5];
vector<e> vc[MAX_10p5];
priority_queue<e, vector<e>, greater<e>> pq;

ll prim() {
	ll nidx = 0, ret = 0;
	repi(i, 1, N) {
		used_idx[nidx] = true;
		repi(i, 0, vc[nidx].size()) {
			if (used_idx[vc[nidx][i].to]) continue;
			pq.push(vc[nidx][i]);
		}
		while (1) {
			e te = pq.top();
			pq.pop();
			if (used_idx[te.to]) continue;
			nidx = te.to;
			ret += te.cost;
			break;
		}
	}
	return ret;
}

int main() {
	cin >> N;
	repi(i, 0, N) {
		ll s, t;
		cin >> s >> t;
		p px; px.x = s; px.idx = i;
		xy[0][i] = px;
		p py; py.x = t; py.idx = i;
		xy[1][i] = py;
	}
	sort(xy[0], xy[0] + N);
	sort(xy[1], xy[1] + N);
	repi(i, 0, 2) {
		repi(j, 1, N) {
			ll cost = xy[i][j].x - xy[i][j - 1].x;
			e e1, e2;
			e1.cost = e2.cost = cost;
			e1.to = xy[i][j].idx, e2.to = xy[i][j - 1].idx;
			vc[xy[i][j - 1].idx].push_back(e1);
			vc[xy[i][j].idx].push_back(e2);
		}
	}
	cout << prim() << endl;
	return 0;
}
