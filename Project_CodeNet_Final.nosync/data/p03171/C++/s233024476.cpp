#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e3+5;
#define ll long long
#define pb push_back

ll dp[MAXN][MAXN];
ll vis[MAXN][MAXN];

vector<ll> T;

ll result(int left, int right) {
	if(vis[left][right])
		return dp[left][right];
	vis[left][right] = true;
	if(left == right) {	 
		dp[left][right] = T[left];
		return dp[left][right];
	}
	dp[left][right] = max(T[left] - result(left+1, right), T[right] - result(left, right-1));
	return dp[left][right];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int n;	cin >> n;
	for(int i=0; i<n; i++) {
		ll x;	cin >> x;
		T.pb(x);
	}
	cout << result(0, n-1);	
}
