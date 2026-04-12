#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<math.h>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


ll const MOD = 1e9 + 7;
ll mod_p(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return x * y%MOD;
}

ll mod_pow(ll x, ll t) {
	x %= MOD;
	if (t == 0) {
		return 1;
	}
	else {
		ll v = mod_pow(x, t / 2);
		if (t % 2 == 0) {
			return v * v % MOD;
		}
		else {
			return v * v%MOD * x %MOD;
		}
	}
}

ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

struct edge
{
	ll from; long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};

ll const MAX = 1e5 + 5;
vll G[MAX];
ll n;
ll visited[MAX] = {};

ll f(ll start) {
	visited[start] = 1;
	ll res = 0;
	for (auto next : G[start]) {
		if (visited[next]) {
			continue;
		}
		else {
			ll t = f(next);
			if (t >= 2) {
				return 2;
			}
			else if(t == 0){
				res++;
			}
		}
	}
	return res;
}

int main() {
	cin >> n;
	REP(i, 1, n - 1) {
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll start = 1;
	ll tmp = f(start);
	if (tmp >= 2 || tmp == 0) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
}