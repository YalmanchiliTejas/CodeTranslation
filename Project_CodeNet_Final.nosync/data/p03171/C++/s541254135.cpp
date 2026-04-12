#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e15

ll dp[3005][3005];


ll ans(int l, int r, vector<ll> &vec);

int
main(void){
	int n; cin >> n;
	vector<ll> vec(n);
	
	for(int i = 0; i < n; i++) cin >> vec[i];
	
	for(int i = 0; i < n + 5; i++){
		for(int j = 0; j < n + 5; j++){
			dp[i][j] = INF;
		}
	}
	
	cout << ans(0, n - 1, vec);
	
}

ll ans(int l, int r, vector<ll> &vec){
	if(l == r) return dp[l][r] = vec[l];
	if(dp[l][r] != INF) return dp[l][r];
	
	dp[l][r] = max(vec[l] - ans(l + 1, r, vec), vec[r] - ans(l, r - 1, vec));
	return dp[l][r];
	
}