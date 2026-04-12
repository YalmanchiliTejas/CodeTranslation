#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll mod = (ll)1e9 + 7;
const ll mxN = 200200;



void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll x,y;
	cin>>x>>y;
	ll aa,bb,cc;
	aa=x*a+y*b;
	bb=max(x,y)*2*c;
	cc=min(x,y)*2*c+(max(x,y)==x)*(x-y)*a + (max(x,y)==y)*(y-x)*b;
	cout<<min({aa,bb,cc});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(20);
	cout << fixed;

	//ll t;cin>>t;while(t--)
	solve();

}
