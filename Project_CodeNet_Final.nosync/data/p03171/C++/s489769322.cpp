// dile a la jardinera que traigo flores
// corner cases // int vs ll // cin vs scanf
#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define FER(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define N 3050
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int n;
ll a[N],dp[N][N][2];

ll go(int i, int j, int t){
	ll &ans = dp[i][j][t];
	if(ans != -1) return ans;
	ans = -go(i+1,j,1-t) + a[i];
	ans = max(ans,-go(i,j-1,1-t)+a[j]);
	return ans;
}

int main(){

	fastio;
	cin >> n;
	fill(dp,-1);
	FER(i,0,n) cin >> a[i];
	FER(i,0,n) dp[i][i][0] = dp[i][i][1] = a[i];
	cout << go(0,n-1,0) << endl;

	return 0;
}
