#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int32_t main(){
	cin.tie(0); ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int dp[n][n];
	memset(dp, 0, sizeof dp);
	int r;
	for(int tam = 0; tam < n; tam++){
		for(int l = 0; l + tam < n; l++){
			r = l+tam;
			if(l == r)
				dp[l][r] = a[r];
			else
				dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
		}
	}
	
	cout << dp[0][n-1] << endl;
}
