#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

// #define for(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18

ll mod = 1e9+7;

ll dp[200000][3];
ll A[200000];
void rec1(ll i){
	if (i==0){
		dp[i][0] = A[i*2];
		dp[i][1] = A[i*2+1];
	}
	dp[i+1][0] = dp[i][0] + A[i*2+2];
	dp[i+1][1] = max(dp[i][0] + A[i*2+2+1], dp[i][1] + A[i*2+2+1]);
}

void rec2(ll i){
	if (i==0){
		dp[i][0] = A[i*2];
		dp[i][1] = A[i*2+1];
		dp[i][2] = A[i*2+2];
	}
	dp[i+1][0] = dp[i][0] + A[i*2+2];
	dp[i+1][1] = max(dp[i][0] + A[i*2+2+1], dp[i][1] + A[i*2+2+1]);
	dp[i+1][2] = max(max(dp[i][0] + A[i*2+2+2], dp[i][1] + A[i*2+2+2]), dp[i][2]+ A[i*2+2+2]);
}

// 検索タグ
int main() {
	// 入力
	ll N;cin>>N;
    REP(i,N)cin>>A[i];

	// 解法
	ll ans;
	if (N%2==0){
		REP(i,N/2) rec1(i);
		ans = max(dp[N/2-1][0], dp[N/2-1][1]);
	}
	else{
		REP(i,N/2) rec2(i);
		ans = max(dp[N/2-1][0], dp[N/2-1][1]);
		ans = max(ans, dp[N/2-1][2]);
	}
	//出力
	printf("%lld\n", ans);
}
