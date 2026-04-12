#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	vector<int> arr(n);
  	for(int i = 0;i<n;i++){
    	cin>>arr[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
  	for(int s = 1;s<=n;s++){
   		for(int i = 0;i<=n-s;i++){
        	int turn = (n-s)%2;
          	int j = i+s-1;
          	if(turn==0){
              	long long l = j>0 ? dp[i][j-1] + arr[j] : arr[j];
                long long r = i<n-1 ? dp[i+1][j] + arr[i] : arr[i];
            	dp[i][j] = max(l,r);  
            }
         	if(turn==1){
          		long long l = j>0 ? dp[i][j-1] - arr[j] : -arr[j];
                long long r = i<n-1 ? dp[i+1][j] - arr[i] : -arr[i];
            	dp[i][j] = min(l,r);  
           }
        }
      
    }
	cout<<dp[0][n-1]<<endl;
}