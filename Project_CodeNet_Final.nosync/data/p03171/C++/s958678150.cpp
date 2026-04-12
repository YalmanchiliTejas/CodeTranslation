#include <iostream>
using namespace std;
long long int PredictTheWinner(long long int A[], int n){
        
       long long int dp[n][n];
       long long int sum[n][n];
        sum[0][0] = A[0];
        dp[0][0] = A[0];
 
        for (int i = 1; i < n; ++i) {
            sum[0][i] = sum[0][i - 1] + A[i];
            sum[i][i] = A[i];
            dp[i][i] = A[i];
            for (int j = i - 1; j >= 0; --j) {
                sum[j][i] = sum[0][i] - (j == 0 ? 0 : sum[0][j - 1]);
                dp[j][i] = max(sum[j][i] - dp[j + 1][i],  sum[j][i] - dp[j][i - 1]);
            }
        }
        return dp[0][n-1]-(sum[0][n - 1]-dp[0][n - 1]);
    }
int main() {
	// your code goes here
   std::ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<PredictTheWinner(a,n);
	return 0;
}