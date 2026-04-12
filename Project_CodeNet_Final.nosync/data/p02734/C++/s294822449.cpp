#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>

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

ll dp[3333][3333];
void mod_add(ll &a, ll b){
	a += b;
	a %= MOD;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	ll n, s;cin >> n >> s;
	vector<ll> v(n);REP(i, n)cin >> v[i];

	REP(i, n){
		mod_add(dp[i+1][v[i]], i + 1);
		for(ll j = 1;j < 3333;j++){
			if(j + v[i] < 3333)mod_add(dp[i+1][j+v[i]], dp[i][j]);
			mod_add(dp[i+1][j], dp[i][j]);
		}
	}

	ll ans = 0;
	REP(i, n)mod_add(ans, dp[i+1][s]);
	cout << ans << endl;

	//SHOW2d(dp, n+1, s+1);

	return 0;
}
