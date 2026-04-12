#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll long long int
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<char>	vc;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
#define br "\n"
#define ff first
#define ss second
ll MAX =  (ll)1000005;
ll mod =  1e9 + 7;

vll v,a;
void solve(){
    ll n;
    cin >> n;
    v.resize(n);
    a.resize(n + 1);
    a[0] = 0;
    rep(i,0,n){
        cin >> v[i];
        a[i + 1] = (a[i] + v[i]) % mod;
    }
    ll ans = 0;
    rep(i,0,n){
        ans = (ans + (v[i]*((a[n] - a[i + 1]) + mod)) % mod) % mod;
    }
    cout << ans;

    
}
	

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  

	ll t = 1;
	// cin >> t;
	rep(i,0,t){
		solve();
	}
 
}	