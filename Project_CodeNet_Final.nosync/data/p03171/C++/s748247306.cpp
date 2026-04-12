#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[3005];
ll dp[3005][3005];


int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(i == j){
				dp[i][j] = arr[i];
			}else{
				dp[i][j] = max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
			}
		}
	}
	
	cout << dp[0][n-1] << endl;
	
}