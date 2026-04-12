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
#define MAX 1000003

ll mod = (ll)998244353;

ll n,x,m;
vll prefsum;
set<ll> s;

ll dem(ll j,ll rem){
    vll v;
    v.pb(0);
    rep(i,j,prefsum.size()){
        v.pb(prefsum[i] - prefsum[i - 1] + v.back());
    }
    return (v[rem % (v.size() - 1)] + (v.back()*(rem/(v.size() - 1))));
}

void solve(){ 
    cin >> n >> x >> m;
    prefsum.pb(0);
    rep(i,1,n + 1){
        prefsum.pb(prefsum.back() + x);
        s.insert(x);
        (x *= x) %= m;
        if(!s.empty() && s.find(x) != s.end()){
            rep(j,1,prefsum.size()){
                if(prefsum[j] - prefsum[j - 1] == x){
                    cout << prefsum.back() + dem(j,n - i);
                    return;
                }
            }
        }
    }
    cout << prefsum.back() << br;;

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