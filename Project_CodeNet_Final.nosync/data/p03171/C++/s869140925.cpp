#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll dp[3005][3005][2]; //limit to check if 0 then turn of X else turn of y 
ll ans(int i, int j, int arr[], bool limit){
	if(i > j)
		return 0;
	if(dp[i][j][limit] != -1)
		return dp[i][j][limit];
	if(!limit){
		ll uno = ans(i+1, j, arr, !limit) + arr[i];
		ll dos = ans(i, j-1, arr, !limit) + arr[j];
		return dp[i][j][limit] = max(uno, dos);
		}
	else{
		ll uno = ans(i+1, j, arr, !limit) - arr[i];
		ll dos = ans(i, j-1, arr, !limit) - arr[j];
		return dp[i][j][limit] = min(uno, dos);
		}
		
	}


int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		}
	cout << ans(0, n-1, arr, 0) << endl;
	
	return 0;
	}
