//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/dp/tasks/dp_l
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
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;

int N;
LL a[3000];

LL ans = INF;

void solve(){
	vector<vector<LL>> dp(N+1,vector<LL>(N+1,0));
	// dp[i][j] :
	//  ai+1からajでゲームをするときのX-Yの最大値
	//  ただし、手番は「元のゲームを行ってその局面になった時の手番」とする
 
	for(int len=1;len<=N;len++){
		for(int left=0;left<N-len+1;left++){
			int right = left + len;
			if((N - len) % 2 == 0){
				dp[left][right] = max(dp[left+1][right]+a[left],dp[left][right-1]+a[right-1]);
			}else{
				dp[left][right] = min(dp[left+1][right]-a[left],dp[left][right-1]-a[right-1]);
			}
		}
	}
	ans = dp[0][N];
}
 
int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> a[i];
 
	solve();

	cout << ans << endl;
	return 0;
}