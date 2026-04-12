#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}

ll f(ll x, ll m){ return x*x % m;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll n, x, m;
	cin >>n >>x >>m;
	
	VL cx(100100);
	cx[0] = x;
	rep(i, 100100) cx[i+1] = f(cx[i], m);
	//for(auto x :cx) cerr<<x<<" "; dbg();
	
	
	ll ans =0;
	if(n<100010){
		rep(i, n) ans += cx[i];
	}else{
	
		map<ll, int> mp;
		int st=0,ss=0;
		rep(i, 100999){
			if(mp.count(cx[i])){ st=mp[cx[i]]; ss=i; break;}
			mp[cx[i]] = i;
		}
		ll lp=ss - st;
		ll su = (n-st) / lp;
		ll sm =0;
		rep2(i, st, ss) sm += cx[i];
		ans = su * sm;
		ll am = (n-st)%lp;
		rep(i, st) ans += cx[i];
		rep2(i, st, st+am) ans += cx[i];
	}
	cout << ans <<"\n";
	return 0;
}

