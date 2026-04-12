#include "bits/stdc++.h"

#define REP(i, n ,N) for(ll i = (n); i < (N); i++)
#define RREP(i, n ,N) for(ll i = (N-1); i >= (n); i--)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll inf = 1e18;

string N;
ll K;
ll dp[110][5][2];
int main(){
	cin >> N >> K;
	ll M = N.size();
	//dp[桁][条件][less] := 左からi桁目まで、条件やlessを満たしているかCheck!!
	dp[0][0][0] = 1;
	REP(i,0,M) {
		REP(j,0,K+1){
			REP(less,0,2) {
				ll lim = less ? 9 : N[i] - '0'; //すでにlessならその後は9まで見てよし
				REP(x, 0, lim + 1) {
					if(j + (x != 0) <= K) dp[i + 1][j + (x != 0)][less || x < lim] += dp[i][j][less];
				}
			}
		}
	}

	p(dp[M][K][1] + dp[M][K][0]);

	return 0;
}