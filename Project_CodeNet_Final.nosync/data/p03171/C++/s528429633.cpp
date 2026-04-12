#include <bits/stdc++.h>
typedef long long int ll;
#define vaibhavv06               \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(0);
#define endl '\n'
#define int long long
#define MM(a,b) memset(a,b,sizeof(a))
const ll MOD = 1000000007;
using namespace std;


int32_t main(){
    vaibhavv06;
	int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int dp[n+1][n+1];
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j]=arr[i];
            else dp[i][j] = max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}