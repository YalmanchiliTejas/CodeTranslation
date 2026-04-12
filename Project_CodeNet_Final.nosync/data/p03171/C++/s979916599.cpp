#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int N;
ll dp[3010][3010] = {},A[3010];

ll rec(int i,int j){
	if(i==j) return N%2==1? A[i]:-A[i];
	if(abs(dp[i][j])!=(ll) 1e18) return dp[i][j];
	if((N-(j-i))%2==1) dp[i][j] = max(rec(i+1,j)+A[i],rec(i,j-1)+A[j]);
	else dp[i][j] = min(rec(i+1,j)-A[i],rec(i,j-1)-A[j]);
	return dp[i][j];
}

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	for(int i=1;i<N;i++){
		for(int j=i+1;j<=N;j++){
			if((N-(j-i))%2==1) dp[i][j] = 1e18;
			else dp[i][j] = -1e18;
		}
	}
	cout << rec(1,N) << endl;
}