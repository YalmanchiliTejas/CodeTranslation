// #include "debug.h"
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

ll n, m;
ll a[maxn];
vi g[maxn];

void solve() {
	cin >> n;
	if (n >= 30) cout << "Yes";
	else cout << "No";
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