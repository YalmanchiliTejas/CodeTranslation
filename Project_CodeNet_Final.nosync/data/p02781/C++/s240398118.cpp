#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
typedef long long ll;
typedef long double ld;
using namespace std;

ll dp[110][10][5][2];

int main() {
	string N;
	int K;
	cin >> N >> K;
	dp[0][0][0][0]=1;
	for(int i=0; i<N.size(); ++i){
		for(int j=0; j<10; ++j){
			for(int k=0; k<K; ++k){
				dp[i+1][0][k][1] += dp[i][j][k][1];
				for(int d=1; d<10; ++d){
					dp[i+1][d][k+1][1] += dp[i][j][k][1];
				}
			}
			dp[i+1][0][K][1] += dp[i][j][K][1];
			int dg=N[i]-'0';
			for(int d=0; d<dg; ++d){
				if(d==0){
					for(int k=0; k<=K; ++k){
						dp[i+1][d][k][1] += dp[i][j][k][0];
					}
				}else{
					for(int k=0; k<K; ++k){
						dp[i+1][d][k+1][1] += dp[i][j][k][0];
					}
				}
			}
			if(dg==0){
				for(int k=0; k<=K; ++k){
					dp[i+1][dg][k][0] += dp[i][j][k][0];
				}
			}else{
				for(int k=0; k<K; ++k){
					dp[i+1][dg][k+1][0] += dp[i][j][k][0];
				}
			}
		}
	}
	ll ans=0;
	for(int i=0; i<10; ++i){
		ans += dp[N.size()][i][K][0]+dp[N.size()][i][K][1];
	}
	cout << ans << endl;
	return 0;
}