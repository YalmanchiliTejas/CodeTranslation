#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 , M = 1e3; ;
int n;
int a[N];
int dp[4*M][4*M][2];
int foo(int start , int end ,int chance  ){
	if(start > end) return 0;
	if(dp[start][end][chance]!=-1) return dp[start][end][chance]; 
	int ans = 0;
	if(chance) ans = max( a[start] + foo(start + 1 , end , chance^1) , a[end] + foo(start , end - 1 , chance^1) );
	else ans = min( -a[start] + foo(start + 1 , end , chance^1) , -a[end] + foo(start , end - 1 , chance^1) );   
	dp[start][end][chance] = ans; 
	return ans;
}


int32_t main(){
	cin >> n;
	memset(dp , - 1 , sizeof dp);
	for(int i = 1 ; i <= n ;i++){
		cin >> a[i];
	}
	cout << foo(1 , n , 1) << "\n"; 
	return 0;
}