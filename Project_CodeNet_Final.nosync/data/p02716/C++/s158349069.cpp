#include <iostream>
#include <climits>
#define MAXN 200000
using namespace std;
long long mymax(long long a, long long b){
	const long long lb = LLONG_MIN + INT_MAX, ub = LLONG_MAX - INT_MAX;
	if(a < lb || a > ub)
		a = LLONG_MIN;
	if(b < lb || b > ub)
		b = LLONG_MIN;
	return max(a, b);
}
int main(){
	int N, a[MAXN];
	long long dp[MAXN][4] = {0}; // 0, 12, 13, 22
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];
	dp[0][0] = a[0], dp[0][1] = LLONG_MIN, dp[0][2] = LLONG_MIN, dp[0][3] = LLONG_MIN;
	dp[1][0] = LLONG_MIN, dp[1][1] = a[1], dp[1][2] = LLONG_MIN, dp[1][3] = LLONG_MIN;
	dp[2][0] = a[0]+a[2], dp[2][1] = LLONG_MIN, dp[2][2] = a[2], dp[2][3] = LLONG_MIN;
	dp[3][0] = LLONG_MIN, dp[3][1] = max(a[0], a[1])+a[3], dp[3][2] = LLONG_MIN, dp[3][3] = LLONG_MIN;
	//cout << a[2] << " " << 
	for(int i=4; i<N; i++){
		dp[i][0] = mymax(dp[i-2][0] + a[i], LLONG_MIN);
		dp[i][1] = mymax(dp[i-3][0] + a[i], dp[i-2][1] + a[i]);
		dp[i][2] = mymax(dp[i-4][0] + a[i], dp[i-2][2] + a[i]);
		dp[i][3] = mymax(dp[i-3][1] + a[i], dp[i-2][3] + a[i]);
	}
	//for(int i=0; i<N; i++)
		//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
	if(N % 2)
		cout << max(max(dp[N-3][0], dp[N-2][1]), max(dp[N-1][2], dp[N-1][3])) << endl;
	else
		cout << max(dp[N-1][1], dp[N-2][0]) << endl;
}

