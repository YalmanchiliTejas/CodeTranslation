#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ull unsigned ll
#define pb push_back
#define popb pop_back
#define mt make_tuple
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int,int>
#define piii pair <pii,int>
#define piiii pair <pii,pii>
#define plll pair <pair <ll, ll>, ll>
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define reprev(i,n) for(ll i=n;i>=0;i--)
#define all(c) c.begin(),c.end()
#define print(a) rep0(i,a.size()) cout << a[i] << " "
#define hi() cout << "\nHello, I am error. Can you find me? :):):)\n"
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_eppoch().count())
 
using namespace __gnu_pbds;
using namespace std;
using ordered_set =  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

const int mod = 1e9+7;
const long double pi = acos(-1);

ll power(ll x, ll y){
	x %= mod;
	if(y == 0) return 1;
	if(y == 1) return x;
	ll num = power(x,y/2) % mod;
	if(y%2 == 0) return (num*num)%mod;
	else return (((num*num)%mod)*x)%mod;
}

ll fun(ll n, ll x){
	ll num = 1;
	rep0(i,n+2) num *= 2;
	num -= 3;

	ll tmp = 1;
	rep0(i,n+1) tmp *= 2;
	tmp -= 1;

	if(n == 0) return 1;
	if(x == 1) return 0;
	if(x < num/2) return fun(n-1,x-1);
	if(x == num/2) return fun(n-1,x);
	if(x == num/2 + 1) return fun(n-1,x) + 1;
	if(x >= num) return 2*fun(n-1,x) + 1;
	return fun(n-1,x) + 1 + fun(n-1,x-tmp);
}

void solve(){

	ll n, x;
	cin >> n >> x;
	ll ans = fun(n, x);
	cout << ans;

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC = 1,t = 0;
	// cin >> TC;
	while(t++ < TC){
		// cout << "Case #" << t << ": ";
		solve();
		// cout << "\n";
	}

	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

	return 0; 
}