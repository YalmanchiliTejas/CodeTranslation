#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
const ll MOD = 1e9 + 7;

int mainsolve(){

	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	map<P,ll> dp; // dp[P(now,cnt)] = val : nowから始めてcnt個とるときの最大値val
  	dp[P(n-1,1)] = a[n-1];
  	if(n-2 >= 0) dp[P(n-2,1)] = max(a[n-1],a[n-2]);

	for(ll now = n-3; now >= 0; now--){

      ll tmp;
      if((n-now)%2 == 0) tmp = (n-now)/2;
      else tmp = (n-now)/2 + 1;
      
		for(ll cnt = max(1ll,tmp-2); tmp >= cnt; cnt++){
			ll dpUse, dpNotUse;
			if(!dp.count(P(now+1,cnt))) dpNotUse = -1e18;
			else dpNotUse = dp[P(now+1,cnt)];
			if(!dp.count(P(now+2,cnt-1))) dpUse = -1e18;
			else dpUse = dp[P(now+2,cnt-1)];

			//dp[P(now,cnt)] = max(dp[P(now+1,cnt)], dp[P(now+2,cnt-1)] + a[now]);
			dp[P(now,cnt)] = max(dpNotUse, dpUse + a[now]);
		}      
      
	}


	cout << dp[P(0,n/2)] << endl;
	return 0;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}
