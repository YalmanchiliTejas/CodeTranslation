#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
int N;
long long int X,dp[51],d[51],ans=0;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> X;
	dp [0] = d[0] = 1;

	REP(i,N){
		dp[i + 1] = dp[i] * 2 + 3;
		d[i + 1] = d[i] * 2 + 1;
	}
	while (X) {
		if(X >= dp[N]){
			ans += d[N];
			X = 0;
			break;
		}
		else if(X - 1 < dp[N-1]){
			N--;
			X--;
			continue;
		}
		else if(X == dp[N-1] + 1){
			ans += d[N-1];
			X = 0;
			break;
		}
		else{
			ans += d[N - 1] + 1;
			X -= dp[N - 1] + 2;
			N--;
		}
	}
	cout << ans << endl;
}