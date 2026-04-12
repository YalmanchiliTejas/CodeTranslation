#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
	int n; cin >> n;
	vector<ll> A(n + 1, 0), greedy(n + 1, 0), dp(n + 1, 0);
	
	for(int i = 1; i <= n; i ++) cin >> A[i];
	greedy[1] = A[1];
	for(int i = 3; i <= n; i += 2){
		greedy[i] = greedy[i - 2] + A[i];
	}
	for(int i = 2; i <= n; i ++){
		if(i & 1){
			dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
		}
		else{
			dp[i] = max(dp[i - 2] + A[i], greedy[i - 1]);
		}
	}
	cout << dp[n] << endl;
}