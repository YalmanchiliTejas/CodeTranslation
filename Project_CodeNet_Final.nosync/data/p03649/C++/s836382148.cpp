#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;


int main(){
	int n;
	cin >> n;
	vl a(n);
	rep(i, n) cin >> a[i];
	ll ans = 0LL;
	sort(rall(a));
	while(1) {
		ll cnt = 0LL;
		// rep(i, n) if(a[i] >= n) {
		// 	cnt = a[i] / n;
		// 	rep(j, n) if(i != j) a[j] += cnt;
		// 	a[i] %= n;
		// 	break;
		// } 
		// if(cnt) ans += cnt;
		// else break;
		sort(rall(a));
		if(a[0] < n) break;
		cnt = a[0] / n;
		a[0] %= n;
		REP(i, 1, n) a[i] += cnt;
		ans += cnt;
	}
	cout << ans << endl;
	return 0;
}