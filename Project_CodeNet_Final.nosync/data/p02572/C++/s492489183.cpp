#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

ll power(ll x, ll y) {
	if (y==0) return 1;
	else if (y==1) return x%MOD;
	else if (y%2==0) { ll pow=power(x,y/2); return (pow*pow)%MOD; } 
	else { ll pow=power(x,y/2); return ((pow*pow)%MOD)*x%MOD; }
}
ll divid(ll x, ll y) {
	return ((x%MOD)*power(y,MOD-2))%MOD;
}

int main(){
	int n; cin >> n;
	VI a(n); REP(i,n) cin >> a[i];
	ll sum=0;
	REP(i,n) sum+=a[i];
	sum%=MOD;
	ll ans=0;
	REP(i,n){
		ans+=a[i]*(sum-a[i]+MOD)%MOD;
		ans%=MOD;
	}
	cout << divid(ans,2) << endl;
	return 0;
}