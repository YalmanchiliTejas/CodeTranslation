#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 998244353
#define pi 3.14159265358979323846
#define Endl endl
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int dp[3141][6141];
signed main(){
	int n,s;
	cin>>n>>s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){ cin>>a[i]; }
	dp[0][0] = 1;
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<s;j++){
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= inf;
			if( j == 0 ){
				dp[i][ j+a[i] ] += i * dp[i-1][j] ;
				dp[i][ j+a[i] ] %= inf;
			}
			else{
				dp[i][ j+a[i] ] += dp[i-1][j];
				dp[i][ j+a[i] ] %= inf;
			}
		}
		ans += ( n - i + 1 ) * dp[i][s];
		ans %= inf;
	}
	cout<<ans<<Endl;
	return 0;
}