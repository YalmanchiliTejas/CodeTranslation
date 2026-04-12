#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;

using vs = vector<string>;

using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;

using tll = tuple<ll,ll,ll>;
using vtl = vector<tll>;

using vb = vector<bool>;
using vvb = vector<vb>;

using ld = long double;
using vd = vector<ld>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;

#define R(a,i) for(ll a=0; a < (i); (a)++)
#define FOR(a,i,j) for(ll a=(i); a < (j); (a)++)
#define RD(a,i) for(ll a=(i)-1; (a) >= 0; (a)--)
#define FORD(a,i,j) for(ll a=(j)-1; (a) >= (i); (a)--)

#define xx first
#define yy second
#define pb push_back
#define eb emplace_back

#define all(X) begin(X),end(X)
#define sz(X) (X).size()

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ld eps = 1e-9;

#define DBG 0
#define TR(X) {if(DBG) cerr << (#X) << " = " << (X) << "\n";}
#define TRV(X,i) {if(DBG) cerr << (#X) << "[" << i << "] = " << (X[i]) << "\n";}
#define TRM(X,i,j) {if(DBG) cerr << (#X) << "[" << i << "][" << j << "] = " << (X[i][j]) << "\n";}
#define TRP(X,i,j) {if(DBG) cerr << (#X) << "[" << i << "][" << j << "] = (" << (X[i][j]).xx << ", " << (X[i][j]).yy << ")\n";}
#define hline {if(DBG) cerr << "----------------------------------------------------------------------" << "\n";}
#define PK(X) {if(DBG) cerr << (X) << "\n";}

const ll mod = 1e9+7;

template <class T>
void myMin(T& a, T b){
	a = min(a,b);
}

template <class T>
void myMax(T& a, T b){
	a = max(a,b);
}

#define TRM(X,i,j,k) {if(DBG) cerr << (#X) << "[" << i << "][" << j << "] = " << (X[i][j][k]) << "\n";}
int main(void){
	cin.sync_with_stdio(false);
	cin.tie(0);

	string K;
	ll D;
	cin >> K >> D;

	vvvl dp(10005, vvl(100, vl(2)));

	dp[0][0][0] = 1;

	FOR(len,0,sz(K)) {
		ll cur = K[len] - '0';
		FOR(i,0,D){
			FOR(j,0,cur) {
				dp[len+1][(i+j)%D][1] += dp[len][i][0];
				dp[len+1][(i+j)%D][1] %= mod;
			}
			dp[len+1][(i+cur)%D][0] += dp[len][i][0];
			dp[len+1][(i+cur)%D][0] %= mod;
			FOR(j,0,10){
				dp[len+1][(i+j)%D][1] += dp[len][i][1];
				dp[len+1][(i+j)%D][1] %= mod;
			}
		}
	}

	FOR(len,0,sz(K) + 1){
		FOR(i,0,D){
			FOR(k,0,2){
				TRM(dp,len,i,k);
			}
		}
	}

	cout << ((((dp[sz(K)][0][1] + dp[sz(K)][0][0]) % mod) + mod - 1) % mod) << endl;
}
