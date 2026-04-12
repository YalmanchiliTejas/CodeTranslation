#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin >> n;
	long long int arr[n+1], dp[n+5][n+5];
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	for(int i=n;i>=0;i--){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else if(i==j){
				dp[i][j]=arr[i];
			}
			else{
				dp[i][j]=max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
			}
		}
	}
	cout << dp[1][n] << '\n';
}