#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;


int main(){
	
	int n;cin >> n;
	vector<pair<ll,ll>> v;
	
	REP(i,n){
		ll a,b;cin >> a >> b;
		v.PB(MP(min(a,b),max(a,b)));
	}
	
	sort(ALL(v));
	
	ll rmin = INF;
	ll rmax = 0;
	ll bmin = INF;
	ll bmax = 0;
	REP(i,n){
		rmin = min(rmin,v[i].FI);
		bmin = min(bmin,v[i].SE);
		rmax = max(rmax,v[i].FI);
		bmax = max(bmax,v[i].SE);
	}
	
	ll ans = (rmax - rmin) * (bmax - bmin);
	ll tmp = max(rmax,bmax) - min(rmin,bmin);
	
	rmin = v[0].FI;
	rmax = v[n-1].FI;
	bmin = v[0].SE;
	bmax = v[0].SE;
	
	REP(i,n-1){
		rmin = v[i+1].FI;
		bmin = min(bmin,v[i].SE);
		bmax = max(bmax,v[i].SE);
		ll seica = max(rmax,bmax) - min(rmin,bmin);
		ans = min(ans,tmp * seica);
	}
	
	cout << ans << endl;
	
	return 0;
}
