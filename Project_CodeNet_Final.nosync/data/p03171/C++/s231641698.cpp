#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int n;
ll *a, **dp;

ll recur(int i, int j) {
	if(i == j) return a[i];
	if(dp[i][j]) return dp[i][j];
	return dp[i][j] =  max(a[i] - recur(i+1, j), a[j] - recur(i, j-1));
}

int main() {
	cin >> n;
	
	a = new ll[n];
	dp = new ll*[n];
	for(int i = 0; i < n; i++) dp[i] = new ll[n]; 
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = 0;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	cout << recur(0, n-1);
	
	return 0;
}