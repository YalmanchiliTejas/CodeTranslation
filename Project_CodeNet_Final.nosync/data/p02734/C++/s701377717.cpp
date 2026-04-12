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
//const LL mod = 1000000007ll;
const int mod_int = 1000000007;

const LL mod = 998244353ll;

LL N,S;
LL A[3000];

LL ans = 0;

void solve(){
	//dp[i][j]:
	//L<=x1<=...<=xk<=RかつAx1+...+Axk=jを満たす
	//数列(Ax1,...,Axk)の個数をg(L,R)とおく
	//この時1<=L<=R<=iを満たす整数(L,R)の組全てに対する
	//g(L,R)の和をdp[i][j]とおく
	//こうすれば答えは
	//ans = dp[1][S] + dp[2][S] + ..... + dp[N][S]
	//とすれば良い。
	vector<vector<LL>> dp(N+1,vector<LL>(3001,0));
	for(int i=0;i<N;i++){
		//数列のi番目から見て、0個取るような方法は
		//各iに対して必ず1つずつある
		dp[i][0] += 1;
		//+=1としているのは数列の0~i-1番目それぞれからみて、
		//0個取るような方法が既にdp[i][0]に記録されていなければならないため
		for(int j=0;j<=3000;j++){
			//A[i]を使わない時
			dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
			//A[i]を使う時
			if(j+A[i]<=3000)dp[i+1][j+A[i]] = (dp[i+1][j+A[i]]+dp[i][j])%mod;
		}
	}
	for(int i=0;i<=N;i++) ans = (ans+dp[i][S])%mod;
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}