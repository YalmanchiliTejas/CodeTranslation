#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 998244353;
int main(){
	int n,s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(s+1,vector<ll>(3,0)));
	//dp[i][j][t]:=(t=0で,Lをまだ決めていない状態),(t=1で,Lを決めたがRを決めていない状態),(t=2で,LもRも決めた状態.)
	dp[0][0][0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= s;j++){
			//0->0
			dp[i+1][j][0] += dp[i][j][0];
			dp[i+1][j][0] %= MOD;
			//0->1は取って決める場合と取らずに決める場合の2通り.
			dp[i+1][j][1] += dp[i][j][0];
			dp[i+1][j][1] %= MOD;
			if(j + a[i] <= s){
				dp[i+1][j+a[i]][1] += dp[i][j][0];
				dp[i+1][j+a[i]][1] %= MOD;
			}
			//0->2はそれのみを取る場合.
			if(j + a[i] <= s){
				dp[i+1][j+a[i]][2] += dp[i+1][j][0];
				dp[i+1][j+a[i]][2] %= MOD;
			}

			//1->1はA[i]を取る場合と取らない場合の2通り.
			dp[i+1][j][1] += dp[i][j][1];
			dp[i+1][j][1] %= MOD;
			if(j + a[i] <= s){
				dp[i+1][j+a[i]][1] += dp[i][j][1];
				dp[i+1][j+a[i]][1] %= MOD;
			}

			//1->2は取る場合と取らない場合の2通り.
			dp[i+1][j][2] += dp[i][j][1];
			dp[i+1][j][2] %= MOD;

			if(j + a[i] <= s){
				dp[i+1][j+a[i]][2] += dp[i][j][1];
				dp[i+1][j+a[i]][2] %= MOD;
			}

			//2->2もある.
			dp[i+1][j][2] += dp[i][j][2];
			dp[i+1][j][2] %= MOD;
		}
	}

	cout << dp[n][s][2] << endl;
}
