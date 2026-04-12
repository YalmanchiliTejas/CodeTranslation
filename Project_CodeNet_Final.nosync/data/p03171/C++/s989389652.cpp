#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	//dp[i][j] = diff between X,Y with queue start at i end at j
	ll dp[n+5][n+5];
	//optimal - both player take as large as possible
	//from small (1 element) to large (whole queue) interval
	//i - left, j - right
	for (int i = n - 1; i >= 0; --i){
		for (int j = i; j < n; ++j){
			if (i == j){	//one element
				dp[i][j] = a[i];	//Taro (start first) take one, X = a[i]
			}
			else{
				//take left, take right
				//dp[i+1][j] = diff bf taking left, dp[i][j-1] = diff bf taking right
				dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
			}
		}
	}
	cout << dp[0][n-1] << '\n';
	return 0;
}
/*
IF X chooses (maximize)
x + a - y = a + x - y

IF Y chooses (minimize)
x - (y + a) = -a + x - y

note that x - y is fixed (previous dp state),
X chooses = maximize (a + C)
Y chooses = minimize (-a + C) = maximize (a + C)

a + C = a + x - y = a + dp[previous state]
*/