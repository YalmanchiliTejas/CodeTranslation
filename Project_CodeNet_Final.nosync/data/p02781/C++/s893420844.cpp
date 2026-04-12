#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
template<typename T>
using pque = priority_queue<T, vector<T>, greater<T>>;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 128
char s[N];
ll dp[N][2][4] = {};

int main(){
	int kk; scanf("%s%d", s, &kk); int n = strlen(s);
	dp[0][0][0] = 1;
	REP(i, n){
		REP(j, 2){
			REP(k, 4){
				DEBUG("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
				// use 0
				int jj = j;
				if(s[i] > '0') jj = 1;
				dp[i+1][jj][k] += dp[i][j][k];
				DEBUG(" [%d][%d][%d] => [%d][%d][%d]\n", i, j, k, i+1, jj, k);
				if(k + 1 < 4){
					if(j){
						dp[i+1][1][k+1] += 9 * dp[i][j][k];
						DEBUG(" [%d][%d][%d] * 9 => [%d][%d][%d]\n", i, j, k, i+1, 1, k+1);
					}else if(s[i] > '0'){
						// use non-zero, less
						dp[i+1][1][k+1] += (s[i] - '0' - 1) * dp[i][j][k];
						DEBUG(" [%d][%d][%d] * %d => [%d][%d][%d]\n", i, j, k, (s[i] - '0' - 1), i+1, 1, k+1);
						// use non-zero, equal
						dp[i+1][j][k+1] += dp[i][j][k];
						DEBUG(" [%d][%d][%d] => [%d][%d][%d]\n", i, j, k, i+1, j, k+1);
					} 
				}
			}
		}
	}
	printf("%lld\n", dp[n][0][kk] + dp[n][1][kk]);
}
