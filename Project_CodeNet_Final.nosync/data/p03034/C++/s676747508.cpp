#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    forn(i,n) cin >> a[i];
    map<ll,ll> dp;
    ll fact = 1e6;
    forsn(i,1,n-1){
    	dp[fact*i]=0;
    }
    ll ans=0;
    forsn(i,1,n-1){
    	forsn(j,1,(n-2)/i){
    		if((n-1)%i==0 && 2*i*j>=n-1) continue;
    		dp[fact*i+j]=dp[fact*i+j-1]+a[j*i]+a[n-1-i*j];
    		// cout << i << " " << j << " " << dp[fact*i+j] << ln;
    		ans = max(ans,dp[fact*i+j]);
    	}
    }
    cout << ans << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}