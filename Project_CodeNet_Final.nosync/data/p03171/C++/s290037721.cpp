#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3001;
int dp[N][N];
int arr[N];

int32_t main(){

	int n ;
	cin >> n ; 
	for(int i=0;i<n;i++) cin >> arr[i] ; 

	for(int l=n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if( l == r ){
				dp[l][r] = arr[l];
			}else {
				dp[l][r] = max(arr[l] - dp[l+1][r],arr[r] - dp[l][r-1]);
			}
		}
	}

	cout << dp[0][n-1] << endl ;
	
	return 0;
}
