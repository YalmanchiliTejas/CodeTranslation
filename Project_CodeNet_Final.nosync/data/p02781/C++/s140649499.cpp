//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

string S;
LL K;

LL ans = 0;

void solve(){
	int N = S.size();
	//dp[i][j][k]:
	//Sを上からi桁目まで見た時、
	//未満フラグをjとして
	//0でない数字がちょうどk個あるような数の個数
	vector<vector<vector<LL>>> dp(N+1,vector<vector<LL>>(2,vector<LL>(4,0)));
	dp[0][0][0] = 1;
	//ばらまくイメージのDP
	for(int i=0;i<N;i++){
		for(int k=0;k<=3;k++){
			LL num = S[i] - '0';
			if(dp[i][0][k]){
				if(num==0){
					//0を選択
					dp[i+1][0][k] += dp[i][0][k];
				}
				if(num>=1){
					//0を選択
					dp[i+1][1][k] += dp[i][0][k];
					//1~num-1を選択
					if(k+1<=3) dp[i+1][1][k+1] += dp[i][0][k]*(num-1LL);
					if(k+1<=3) dp[i+1][0][k+1] += dp[i][0][k];
				}
			}
			if(dp[i][1][k]){
				//0を選択
				dp[i+1][1][k] += dp[i][1][k];
				//1~9を選択
				if(k+1<=3) dp[i+1][1][k+1] += dp[i][1][k]*9LL;
			}
		}
	}
	ans = dp[N][0][K] + dp[N][1][K];
}

int main(){
    cin >> S;
    cin >> K;

    solve();

	cout << ans << endl;
    return 0;
}