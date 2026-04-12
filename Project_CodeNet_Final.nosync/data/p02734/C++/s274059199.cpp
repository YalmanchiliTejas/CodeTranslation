#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define F first
#define S second
using namespace std;
int r,c,k,ans = INT_MAX;
int A[3005],dp[3005][3005],sum[3005][3005],n,s;
const int MOD = 998244353;	
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int l = 1; l <= s; l ++) {
		for (int j = 1; j <= n; j++){
			if (A[j] > l) continue;
			if (A[j] == l) dp[j][l] = j,sum[j][l] = (sum[j][l]+ j)%MOD;
			else {
				dp[j][l] = sum[j-1][l - A[j]];
			//	sum[j][l] += j;
				sum[j][l] = (sum[j][l] + dp[j][l])%MOD;		
			}
		}
		for (int j = 1; j <= n; j++)
			sum[j][l] = (sum[j][l] + sum[j-1][l])%MOD;
		}
	int ans = 0;
//	cout << sum[1][s];
	for (int i = 1; i <= n; i++)
	ans = (ans + 1ll*dp[i][s]*(n-i+1)%MOD)%MOD;
cout << ans%MOD;
}