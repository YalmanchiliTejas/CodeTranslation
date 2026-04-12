#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

using ll    = long long;
using vll   = vector<ll>;
using pll   = pair<ll,ll>;
using ld    = long double;

const ll mod = (ll)1e9 + 7;
const ll mxN = (ll)4e5 + 3;

void solve() {
	ll n;cin>>n;
	ll ans=0,msf=-1e18;
	for(int i=0,x;i<n;i++) {
		cin>>x;
		if(x>=msf) ans++,msf=x;
	}
	cout<<ans<<"\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(20);
	cout << fixed;
//	pre();
//	ll t;cin>>t;while (t--)
		solve();
}
