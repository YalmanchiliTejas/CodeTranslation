#include <iostream>
using namespace std;
typedef long long ll;
int N;
ll dp[3010][3010] = {},A[3010];

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		dp[i][i] = A[i];
		if(N%2==0) dp[i][i] *= -1;
	}
	for(int i=1;i<=N-1;i++){
		for(int j=1;j<=N-i;j++){
			if((N-i)%2==1){
				dp[j][j+i] = max(dp[j][j+i-1]+A[j+i],dp[j+1][j+i]+A[j]);
			}else{
				dp[j][j+i] = min(dp[j][j+i-1]-A[j+i],dp[j+1][j+i]-A[j]);
			}
		}
	}
	cout << dp[1][N] << endl;
}