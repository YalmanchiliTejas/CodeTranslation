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
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll dp[2][11111][111];

void modadd(ll &a, ll b){
	a += b;
	a %= MOD;
}

int main(){
	
	string str;cin >> str;
	int d;cin >> d;
	
	dp[0][0][0] = 1;
	REP(i,str.size()){
		REP(j,d){
			REP(k,10){
				int nxt = (j + k) % d;
				modadd(dp[1][i+1][nxt],dp[1][i][j]);
				if((str[i] - '0') == k){
					modadd(dp[0][i+1][nxt], dp[0][i][j]);
				}
				else if((str[i] - '0') > k){
					modadd(dp[1][i+1][nxt], dp[0][i][j]);
				}
			}
		}
	}
		
	cout << (dp[0][str.size()][0] + dp[1][str.size()][0] - 1 + MOD) % MOD << endl;
	
	return 0;
}
