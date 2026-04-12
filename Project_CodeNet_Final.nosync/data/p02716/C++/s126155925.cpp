// https://atcoder.jp/contests/abc162/tasks/abc162_f
// DP 解説動画の手法
// oxoxoxo...xoにxを1コまたは2コ挿入
// i番目まで見たときにjコのxが挿入された場合のMAX　のDP

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

#define MAX_N 200005
const ll INF = 1e18;

int N;
ll a[MAX_N];
ll dp[MAX_N][4];

int main() {
    cin >> N;
	rep(i,N) cin >> a[i];
	int k = 1 + N%2; // 挿入されるxの数
	rep(i,N)rep(j,4)dp[i][j]=-INF;
	rep(j,k+1)dp[0][j+1]=0;

	rep(j,k+1){
		rep(i,N-k){
			if(i%2){
				dp[i+1][j+1]=dp[i][j+1];
			}else{
				dp[i+1][j+1] = max(dp[i][j+1]+a[i+j],dp[i+1][j]);
			}
		}
	}
	cout << dp[N-k][k+1] << endl;
	// rep(j,k+2){
	// 	rep(i,N+1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
    return 0;
}
