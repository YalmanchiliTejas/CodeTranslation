#include <bits/stdc++.h>
using namespace std;
 
//#define kk
#define int long long
#define FOR(i, n) for(int i=1; i<=n; i++)
#define ff first
#define ss second
#define ll int
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const long long INF=1e18+5;
typedef pair<int, int> pi;

int arr[3001];
int dp[3001][3001];

int get(int i, int j){
	if(i>j) return 0;
	if(i==j) return arr[i];
	if(dp[i][j]!=-1) return dp[i][j];
	
	return dp[i][j]=max(arr[i]-get(i+1, j), arr[j]-get(i, j-1));
}

void solve(){
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	memset(dp, -1, sizeof dp);
	cout<<get(1, n)<<endl;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(10);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	//cin>>T;
	
	while(T--){
		solve();
	}
}
