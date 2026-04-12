#include <bits/stdc++.h>                 // [PRIMES]               1777 ~2^10.80
using namespace std;                     //                       10333 ~2^13.33
using ll = long long;                    // seq 1 128 | factor   100333 ~2^16.61
using ld = long double;                  //   | grep -v ' .* '  1300111 ~2^20.31
using vl = vector<ll>;                   //                    10300777 ~2^23.30
using vvl = vector<vl>;                  //                   100400999 ~2^26.58
using pll = pair<ll,ll>;                 //                  1300400999 ~2^30.28
using vpll = vector<pll>;                //                 10200500333 ~2^33.25
using vb = vector<bool>;                 //                100200400777 ~2^36.54
using vs = vector<string>;               //               1200300700111 ~2^40.13
const ll oo = 0x3f3f3f3f3f3f3f3fLL;      //              10200300500777 ~2^43.21
const ld eps = 1e-9;                     //             100200300400777 ~2^46.51
#define sz(c) ll((c).size())             //            1200300400600999 ~2^50.09
#define all(c) begin(c),end(c)           //           10200300400600111 ~2^53.18
#define mp make_pair                     //          100200300400600333 ~2^56.48
#define mt make_tuple                    //         1200300400500800999 ~2^60.06
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define FORD(i,a,b) for(ll i=ll(b)-1;i>=(a);i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n; cin >> n;
	vl as(n); FOR(i,0,n) cin >> as[i];
	vvl dp(n, vl(n, 0));

	FOR(i,0,n) dp[i][i] = as[i];

	FOR(i,1,n) {
		for (ll x = 0; x+i < n; x++) {
			dp[x][x+i] = max(as[x] - dp[x+1][x+i], as[x+i] - dp[x][x+i-1]);
		}
	}

	cout << dp[0][n-1] << "\n";

	return 0;
}
