//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc162/tasks/abc162_f

//参考：
//https://at274.hatenablog.com/entry/2020/04/14/002124

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
#include <stack>
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

LL N;
LL A[200000];

LL ans = -INF;

void solve(){
	//dp[i][j][k]
	//i個目まで見て
	//j=1ならi個目をとったことを表し、j=0ならとっていないことを表す
	//i個の中からk個選ぶ
	vector<vector<map<LL,LL>>> dp(N+1,vector<map<LL,LL>>(2));
	dp[0][0][0] = 0;
	auto chmax = [&](int i,int j,int k,LL new_value){
		if(dp[i][j].count(k)==1) dp[i][j][k] = max(dp[i][j][k],new_value);
		else dp[i][j][k] = new_value;
	};
	auto show_dp = [&](){
		for(int i=0;i<=N;i++){
			for(int j=0;j<=1;j++){
				for(auto iter=dp[i][j].begin();iter!=dp[i][j].end();iter++){
					printf("dp[%d][%d][%lld]=%lld,",i,j,iter->first,iter->second);
				}
				cout << endl;
			}
			cout << endl;
		}
	};
	//ばらまく
	for(int i=0;i<N;i++){
		for(int k=i/2-1;k<=i/2+1;k++){
			if(k<0 || k>N/2) continue;
			if(dp[i][0].count(k)==1){
				chmax(i+1,1,k+1,dp[i][0][k]+A[i]);
				chmax(i+1,0,k,dp[i][0][k]);
			}
			if(dp[i][1].count(k)==1) chmax(i+1,0,k,dp[i][1][k]);
		}
	}

	for(int j=0;j<=1;j++){
		for(auto iter=dp[N][j].begin();iter!=dp[N][j].end();iter++){
			if((iter->first)==N/2) ans = max(ans,iter->second);
		}
	}
	//show_dp();
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}