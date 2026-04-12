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
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

ll mp[111111];
ll s[111111];
ll n, ans;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	cin >> n;
	REP(i, n)cin >> s[i];
	for(ll i = 1;i < n/2;i++){
		ll l = 0;
		ll r = n - 1;
		ll now = 0;
		while(1){
			l += i;
			r -= i;
			if(l > n - 1 || mp[l] == i)break;
			if(r < i || mp[r] == i)break;
			if(l == r)break;
			now += s[l];
			mp[l] = i;
			now += s[r];
			mp[r] = i;
			ans = max(ans, now);
		}
	}

	cout << ans << endl;

	return 0;
}
