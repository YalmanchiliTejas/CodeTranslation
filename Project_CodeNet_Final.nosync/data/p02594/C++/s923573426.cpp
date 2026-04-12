#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define wh(t) while(t--)
#define fi(n) for(ll i = 0; i < n; i++)
#define fj(n) for(ll j = 0; j < n; j++)
#define fu(i,s,e) for(ll i = s; i <=e; i++)
#define fd(i,s,e) for(ll i = s; i >=e; i--)
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define fr first
#define se second
#define sll stack<ll>
#define qll queue<ll>
using namespace std;
const ll M = 1e9+7;
//const ll M = 998244353;

ll pmp(ll x,ll n){ll a = 1;while(n > 0){if(n & 1) a = (a * x)%M;x = (x * x)%M;n = n>>1;}return a;}

void solve(){
	ll x;
	cin >> x;
	if(x < 30) cout << "No\n";
	else cout << "Yes\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	#endif
	ll t;
	t = 1;
	//cin >> t;
	wh(t){
		solve();
	}
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}