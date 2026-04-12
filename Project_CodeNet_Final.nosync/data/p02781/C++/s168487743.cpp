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

ll dp[111][2][5];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	string str;cin >> str;
	ll K;cin >> K;

	dp[0][0][0] = 1;
	REP(i, str.size()){
		REP(smaller, 2){
			REP(zeroNum, 5){
				REP(nxtNum, 10){
					ll nxtZeroNum = zeroNum;
					if(nxtNum != 0)nxtZeroNum = min(4LL, zeroNum+1);
					if(smaller == 0){
						if(nxtNum == str[i] - '0'){
							dp[i+1][smaller][nxtZeroNum] += dp[i][smaller][zeroNum];
						}
						else if(nxtNum <= str[i] - '0'){
							dp[i+1][1][nxtZeroNum] += dp[i][smaller][zeroNum];
						}
					}
					else{
						dp[i+1][smaller][nxtZeroNum] += dp[i][smaller][zeroNum];
					}
				}
			}
		}
	}

	cout << dp[str.size()][1][K] + dp[str.size()][0][K] << endl;

	return 0;
}
