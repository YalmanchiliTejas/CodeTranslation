
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second

#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define int long long
#define ll long long

const int N = 3e3 + 5;
int dp[N][N], a[N], n;	

int rec(int s, int e){
	if(e < s)
		return 0;
	if(dp[s][e] != -LLONG_MAX)
		return dp[s][e];
	return dp[s][e] = max(a[s] - rec(s + 1, e), a[e] - rec(s, e - 1));
}
	
void solve(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];	
	}
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			dp[i][j] = -LLONG_MAX;		
		}	
	}
	cout << rec(0, n - 1);
}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}