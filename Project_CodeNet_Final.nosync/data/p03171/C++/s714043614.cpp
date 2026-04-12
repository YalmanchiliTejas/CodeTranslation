#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define ALL(a) (a).begin() , a.end()

int mod = 1e9 + 7;
int add(int a, int b){
	if(a + b >= mod)return a+ b - mod;
	return a + b;
}
int mul(int a, int b){
	return 1LL * a * b  % mod;
}
int const N =3010;

/********************i**********************************/
ll dp[N][N], vec[N], INF = -5e15;
int n;
ll go(int i, int j){
	if(i > j)return 0;
	else if(i == j)return vec[i];
	else if(dp[i][j] != INF)return dp[i][j];
	else{
		auto &ans = dp[i][j];
		ans = max(vec[i] - go(i+1, j), vec[j] - go(i, j -1));
		return ans;
	}
}
void solve(){
	int n;
	cin >> n;
	for(int x = 0; x<n; x++){
		for(int y = 0; y<n; y++)
			dp[x][y] = INF;
	}
	for(int x =0;x<n; x++)cin >> vec[x];
	cout << go(0,n-1);

}


/******************************************************/
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}