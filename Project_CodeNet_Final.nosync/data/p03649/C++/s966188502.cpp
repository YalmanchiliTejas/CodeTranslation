#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int WWW = 0;WWW < (n);WWW++)cerr << v[WWW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define MOD 1000000007


typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	ll n;cin >> n;
	vector<ll> v(n);
	
	REP(i,n)cin >> v[i];
	
	ll ans = 0;
	
	REP(i,n){
		ll tmp = v[i] - n*n;
		ll pla = max(0LL,tmp / (n + 1));
		ans += pla * (n+1);
		v[i] -= pla * (n + 1);
	}
	DBG(SHOW1d(v,n);)
	while(1){
		sort(ALL(v),greater<ll>());
		if(v[0] < n)break;
		v[0] -= n+1;
		REP(i,n)v[i]++;
		ans++;
	}
	
	cout << ans << endl;
		
		
	return 0;
}
