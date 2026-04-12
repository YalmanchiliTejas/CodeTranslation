#include <iostream>

using namespace std;
long long dp[3010][3010][2] = {},a[3010],ans = 0;//i個取り除いて、左がa[j]のとき0が先手で先攻-後攻
int main(){
	int i,j,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	for(i=0;i<n;i++){
		dp[n-1][i][0] = a[i];
		dp[n-1][i][1] = -a[i];
	}
	for(i=n-2;i>=0;i--){
		for(j=0;j<=i;j++){
			dp[i][j][0] = max(a[j] + dp[i+1][j+1][1],a[n+j-i-1] + dp[i+1][j][1]);
			dp[i][j][1] = min(-a[j] + dp[i+1][j+1][0],-a[n+j-i-1] + dp[i+1][j][0]);
		}
	}
	cout << dp[0][0][0] << endl;
}