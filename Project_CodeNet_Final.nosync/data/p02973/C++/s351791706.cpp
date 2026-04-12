#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define N_MAX 100010
int dp[N_MAX];
int main(void){
	
	int n;cin >> n;
	vector<int> a(n);
	for(int i=0;i < n;i++) cin >> a[i];
	
	fill(dp,dp+n,INF);

	for(int i = n-1;i >= 0;i--){
		*upper_bound(dp,dp+n,a[i]) = a[i];
	}
	cout << lower_bound(dp,dp+n,INF) - dp << endl;
	return 0;
}