#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define endl '\n'
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 998244353
#define F first
#define S second
#ifdef LOCAL
    #include "trace.h"
#else
    #define trace(args...)
#endif
 
ll div_floor(const ll &a,const ll &b) { return a / b - (((a ^ b) < 0) and a % b);}
ll div_ceil(const ll &a,const ll &b) { return a / b + (((a ^ b) >= 0) and a % b);}

void solve(){
	ll n, x, m;
	cin>>n>>x>>m;
	vector<ll> a;
	vector<ll> occur(m, -1);
	a.push_back(x);
	occur[x] = 0;
	
	while(occur[(a.back()*a.back())%m]==-1){
		occur[(a.back()*a.back())%m] = sz(a);
		a.push_back((a.back()*a.back())%m);
	}

	ll repeat = (a.back()*a.back())%m;

	vector<ll> pref_sum(sz(a)+1, 0);
	for(int i = 1; i<=sz(a); i++)
		pref_sum[i] = pref_sum[i-1] + a[i-1];
	if(n<=sz(a))
		cout<<pref_sum[n]<<endl;
	else{
		ll rem = n - sz(a);
		ll ans = pref_sum[sz(a)];
		ll dist = sz(a) - occur[repeat];
		ll sum  = pref_sum[sz(a)] - pref_sum[occur[repeat]];
		ans += (rem/dist)*sum;
		ans += pref_sum[occur[repeat]+rem%dist]-pref_sum[occur[repeat]];
		cout<<ans<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifdef LOCAL
		freopen("inp.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
    	freopen("err.txt", "w", stderr);
	#endif
	ll t=1;
	// cin>>t;
	while(t--)
		solve();
}