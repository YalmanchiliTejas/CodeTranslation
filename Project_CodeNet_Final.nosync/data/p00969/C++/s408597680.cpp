#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define fi first
#define sc second
int n;
vector<int>vec;
int dp[5005][5005];

int main(){
	cin >> n;
	rep(i,n){ int a; cin >> a; vec.pb(a); }
	sort(vec.begin(),vec.end());
	rep(i,n) for(int j=i+1;j<n;j++) dp[i][j] = 2;
	rep(i,n){
		int x = i+1;
		for(int j=i+1;j<n;j++){
			while(x < n && vec[j]-vec[i] > vec[x]-vec[j]) x++;
			if(x == n) break;
			if(vec[j]-vec[i] == vec[x]-vec[j]){
				dp[j][x] = max(dp[j][x],dp[i][j]+1);
			}
		}
	}
	int ans = 0;
	rep(i,n) rep(j,n) ans = max(ans,dp[i][j]);
	cout << ans << endl;
}

