//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
    ll ans = 0;
    ll dp[3][200000] ={};
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
	dp[0][0] = a[0];	dp[0][1] = 0;		dp[0][2] = a[0]+a[2];
	dp[1][0] = 0; 		dp[1][1] = a[1]; 	dp[1][2] = 0;
	dp[2][0] = 0;		dp[2][1] = 0; 		dp[2][2] = a[2];
	for(int i = 3; i <= n-1; i++){
		if(i % 2 == 1){
			dp[0][i] = 0;
			dp[1][i] = max(dp[1][i-2]+a[i], dp[0][i-3]+a[i]);
			dp[2][i] = 0;
		} 
		else
		{
			dp[0][i] = dp[0][i-2] + a[i];
			dp[1][i] = 0;
			dp[2][i] = max(dp[0][i-4]+a[i],  max(dp[1][i-3]+a[i], dp[2][i-2]+a[i]));
		}
	}
	if(n%2==0) cout << max(dp[0][n-2], dp[1][n-1]) << endl;
	else cout << max(dp[0][n-3], max(dp[1][n-2], dp[2][n-1])) << endl;
}