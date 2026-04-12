#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";
#define MOD 1000000007


ll dp[3001][3001];
ll maxValue(vector<int>&arr, int n, int i, int j){
	if(i==j){
		// t1(i)
		return arr[i];
	}
	if(dp[i][j]>-1) return dp[i][j];
	dp[i][j] = max(arr[i]-maxValue(arr,n,i+1,j),arr[j]-maxValue(arr,n,i,j-1));
	return dp[i][j];
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    ll ans = maxValue(arr,n,0,n-1);
    // dp[0][0] = 0;
    // for(int i=1;i<=n;i++){
    // 	for(int j=n-1;j>=0;j--){
    // 		if(i<j)
    // 			dp[i][j] = max(arr[i-1] - dp[i-1][j],arr[j]-dp[i][j+1]);
    // 		if(i==j){
	   //  		dp[i][j] = arr[i-1];
    // 			break;
    // 		}
    // 	}
    // }
    t1(ans)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }

return 0;
}