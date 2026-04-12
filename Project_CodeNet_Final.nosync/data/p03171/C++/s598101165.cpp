#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll A[3005],dp[3005][3005][2];            
int main(){
    int n; cin >> n;
	vector<ll> a(n);
 
	for(int i=0;i<n;i++) {cin >> a[i]; dp[i][i][0] = a[i]; dp[i][i][1] = -a[i];}
 
	for(int i=n-1;i>=0;i--) {
		for(int j=i+1;j<n;j++) {
			dp[i][j][0] = max(a[i] + dp[i+1][j][1],a[j] + dp[i][j-1][1]);
			dp[i][j][1] = min(-a[i] + dp[i+1][j][0],-a[j] + dp[i][j-1][0]);
		}
	}
 
	cout << dp[0][n-1][0] << endl;
}
