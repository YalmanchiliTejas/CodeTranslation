#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using vl=vector<ll>;
using vvl=vector<vl>;
using vs=vector<string>;
using vb=vector<bool>;
using pll=pair<ll,ll>;
using vpll=vector<pll>;
const ll oo=0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define FORD(i,a,b) for(ll i=ll(b)-1;i>=(a);i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

ll MOD = 1000000007;

int main(){
	cin.sync_with_stdio(0);

	ll N;
	cin >> N;
	vl a(N);
	for(ll &l : a) cin >> l;

	ll sum = 0;
	ll res = 0;
	FORD(i, 1, N) {
		sum += a[i];
		sum %= MOD;

		ll add = sum * a[i-1];
		add %= MOD;

		res += add;
		res %= MOD;
	}

	cout << res << endl;
}
