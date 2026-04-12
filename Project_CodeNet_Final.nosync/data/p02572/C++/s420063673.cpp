#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(vs) (ll)(vs.size())
#define rep(i,a,b) for (ll i = a; i < b; ++i)
#define rep_(i,a,b) for (ll i = a; i > b; --i)
#define endl '\n'
const ll mod = 1e9 + 7;

const ll maxn = 1e5;

ll n, x;

// #include "debug.h"
void solve() {
	cin >> n;
	ll sum = 0, sum_sq = 0;
	rep(i, 0, n) {
		cin >> x;
		sum = (sum + x) % mod;
		sum_sq = (sum_sq + x * x) % mod;
	}
	int ans2 = ((((sum * sum) % mod - sum_sq + mod) % mod) + mod) % mod;
	if (ans2 & 1) {
		cout << (((ans2 + mod) / 2) % mod) << endl;
	}
	else {
		cout << (ans2 / 2) << endl;
	} 
}

void aux() {
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout<<fixed<<setprecision(10);
	aux();
	ll _ = 1;
	// cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}