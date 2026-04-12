#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(ll i=0; i<m; i++)
#define FOR(i,n,m) for(ll i=n; i<m; i++)
#define INF 1000000007
#define INFL (1LL << 60)
#define MOD 998244353
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<ll, ll>

ll POW(ll a, ll b){
	if(b==1) return a;
	if(b%2==0) return POW(a*a%INF, b/2);
	return a*POW(a, b-1)%INF;
}

int main(){
	ll l[51], p[51];
	l[0] = 1;
	p[0] = 1;
	REP(i, 50) l[i+1] = 2*l[i]+3;
	REP(i, 50) p[i+1] = 2*p[i]+1;
	ll n, x;
	cin >> n >> x;
	ll ans = 0;
	REP(i, n){
		x--;
		if(x < l[n-i-1]) continue;
		else{
			x -= l[n-i-1];
			ans += p[n-i-1];
			if(x==0) break;
			x--;
			ans++;
		}
	}
	if(x > 0) ans++;
	cout << ans << endl;
	return 0;
} 
