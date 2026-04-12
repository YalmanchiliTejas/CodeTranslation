#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vb = vector<bool>;
using vs = vector<string>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const ld eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl;})
#define modadd(a,b) (a + b) % (1000000007)
#define modmul(a,b) (a * b) % (1000000007)

int main(){
	cin.sync_with_stdio(0);
	
	vl in;
	ll n;
	cin >> n;
	ll l;
	FOR(i,0,n){
		cin >> l;
		in.pb(l);
	}

	ll tailsum = 0;
	ll sum = 0;

	FORD(i,0,n-1){
		tailsum = modadd(tailsum,in[i+1]);
		sum = modadd(sum,modmul(in[i], tailsum));
	}

	cout << sum << endl;
}
