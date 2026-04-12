#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
signed main(){
	ll n; cin>>n;
	vector< pair<ll,ll> > v;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		v.pb(mp(min(x,y),max(x,y)));
	}
	sort(v.begin(),v.end());
	ll ans1 = 0, ans2 = 0;
	vector<ll> r,b;
	for(ll i=0;i<n;i++){
		r.pb( v[i].first );
		b.pb( v[i].second );
	}
	sort( r.begin(),r.end() );
	sort( b.begin(),b.end() );
	ans1 = (r[n-1]-r[0])*(b[n-1]-b[0]);
	ll msa = b[n-1]-r[0];
	multiset<ll> s;
	for(ll i=0;i<n;i++){
		s.insert(r[i]);
	}
	ll lit = *s.upper_bound(-1);
	multiset<ll>::iterator it = s.end(); it--;
	ll big = *it;
	ans2 = big - lit;
	for(ll i=0;i<n;i++){
		it = s.lower_bound(v[i].first);
		s.erase(it);
		s.insert(v[i].second);
		lit = *s.upper_bound(-1);
		it = s.end();it--;
		big = *it;
		if(big-lit<ans2){ans2=big-lit;}
	}
	ans2 *= msa;
	cout<<min(ans1,ans2)<<endl;
	return 0;
}