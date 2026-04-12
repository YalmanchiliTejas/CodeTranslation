#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	ios :: sync_with_stdio(false);
	
	int n;
	
	cin>>n;
	
	long long int total = 0;
	
	vector <int> arr(n);
	
	for(int i=0; i<n; i+=1){
		
		cin>>arr[i];
		
		total += arr[i];
	}
	
	long long int dp[n][n];
	
	for(int i=0; i<n; i+=1){
		
		dp[i][i] = arr[i];
	}
	
	for(int i=0; i+1<n; i+=1){
		
		dp[i][i+1] = max(arr[i],arr[i+1]);
	}
	
	for(int i=2; i<n; i+=1){
		
		for(int j=0; j+i<n; j+=1){
			
			long long int x = arr[j] + min(dp[j+2][j+i],dp[j+1][j+i-1]);
			
			long long int y = arr[j+i] + min(dp[j+1][j+i-1],dp[j][i+j-2]);
			
			dp[j][j+i] = max(x,y);
		}
	}
	
	long long int X = dp[0][n-1];
	
	long long int Y = total - dp[0][n-1];
	
	cout<<X-Y<<endl;
}