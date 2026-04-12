#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 3001;

ll a[N],n,s,dp[N][3];

void add(ll &a, ll b){
	a += b;
	if(a >= MOD) a -= MOD;
	else if(a < 0) a += MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> s;
	for(int i=0;i<n;i++) cin >> a[i];
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=s;j++) add(dp[j][2], -dp[j][1]);
		for(int j=s-a[i];j>0;j--){
			int x = j+a[i];
			add(dp[x][0], dp[j][2]);
			add(dp[x][1], dp[j][1]);
			add(dp[x][2], dp[j][2]);
		}
		add(dp[a[i]][0], (i+1) * (n-i));
		add(dp[a[i]][1], i+1);
		add(dp[a[i]][2], (i+1) * (n-i));
	}
	cout << dp[s][0] << endl;
	return 0;
}

