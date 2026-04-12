#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int dp[101][2][4]={};
// 桁数(0-based)..n未満か..0以外の数字の数

int main(){
	string n;
	int k;
	cin >> n >> k;
	
	dp[0][0][0] = 1;
	FOR(i,1,4) dp[0][0][i] = 0;
	FOR(i,0,4) dp[0][1][i] = 0;
	
	REP(i,n.size()){
		REP(t,k){
			REP(j,10){
				if(j==0){
					if((int)(n[i]-'0') == 0){
						dp[i+1][1][t] += dp[i][1][t];
						dp[i+1][0][t] += dp[i][0][t];
					}else{
						dp[i+1][1][t] += dp[i][1][t] + dp[i][0][t];
					}
				}else if(j < (int)(n[i]-'0')){
					dp[i+1][1][t+1] += dp[i][1][t] + dp[i][0][t];
				}else if(j == (int)(n[i]-'0')){
					dp[i+1][0][t+1] += dp[i][0][t];
					dp[i+1][1][t+1] += dp[i][1][t];
				}else{
					dp[i+1][1][t+1] += dp[i][1][t];
				}
			}
		}
		if((int)(n[i]-'0') == 0){
			dp[i+1][1][k] += dp[i][1][k];
			dp[i+1][0][k] += dp[i][0][k];
		}else{
			dp[i+1][1][k] += dp[i][1][k] + dp[i][0][k];
		}
	}
	
	/*
	REP(i,n.size()+1){
		REP(j, k+1){
			cout << dp[i][0][j]<<"&"<<dp[i][1][j] << " ";
		}
		cout << endl;
	}
	
	int ans=0;
	FOR(i,1,n.size()+1){
		ans += dp[i][0][k];
		ans += dp[i][1][k];
	}*/
	
	cout << dp[n.size()][1][k]+dp[n.size()][0][k] << endl;
	
	return 0;
}