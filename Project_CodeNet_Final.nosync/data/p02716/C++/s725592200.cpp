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

ll dp[222222][4];

void chMax(ll &a, ll b){
	a = max(a, b);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	ll n;cin >> n;
	vector<ll> v(n);REP(i, n)cin >> v[i];

	REP(i, 222222)REP(j, 4)dp[i][j] = -LLINF;
	dp[0][0] = 0;

	REP(i, n){
		if(i == n-1){
			REP(j, 4){
				chMax(dp[i+1][min(3LL, j+1)], dp[i][j]);
				if(n % 2 && j == 0)continue;
				chMax(dp[min(n, i+2)][j], dp[i][j] + v[i]);
			}
		}
		else{
			REP(j, 4){
				chMax(dp[i+1][min(3LL, j+1)], dp[i][j]);
				chMax(dp[min(n, i+2)][j], dp[i][j] + v[i]);
			}
		}
	}

	if(n % 2){
		cout << max(dp[n][1], dp[n][2]) << endl;
	}
	else{
		cout << max(dp[n][0], dp[n][1]) << endl;
	}

	return 0;
}
