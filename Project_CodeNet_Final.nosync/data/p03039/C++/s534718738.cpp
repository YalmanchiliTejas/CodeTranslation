#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(int i=0; i<m; i++)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define INF 1000000007
#define INFL (1LL << 60)
#define MOD 998244353
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<ll, ll>

ll POW(ll a, ll b){
	if(b==0) return 1LL;
	if(b%2==1) return a*POW(a,b-1)%INF;
	return POW(a*a%INF, b/2);
}

int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0;
	REP(i, n){
		ans += (m*m*(n-i)*i)%INF;
		ans %= INF;
	}
	REP(i, m){
		ans += (n*n*(m-i)*i)%INF;
		ans %= INF;
	}
	FOR(i, n*m-k+1, n*m-1) (ans *= i) %= INF;
	FOR(i, 1, k-1) (ans *= POW(i, INF-2)) %= INF;
	cout << ans << endl;
	return 0;
} 
