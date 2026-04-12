#include <bits/stdc++.h>
#define int long long 
const int MODN=998244353;
const int MAXN=3010;
using namespace std;

int dp[2][MAXN];
//滚动数组
int32_t main(){
    dp[0][0]=1;
    int cur=1;
    int n,k;cin>>n>>k;
    vector<int> arrmv(n+1);
    for(int i=0;i<n;i++)cin>>arrmv[i+1];
    vector<int> a=arrmv;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(k-a[i]>=0){
            if(k-a[i]>0)ans+=dp[cur][k-a[i]]*(n-i+1);
            else ans+=i*(n-i+1);
                ans%=MODN;
        }
        cur=!cur;
        for(int j=k;j>=0;j--){
            dp[cur][j]=0;
            dp[cur][j]+=dp[!cur][j];
            if(j-a[i]>0)dp[cur][j]+=dp[!cur][j-a[i]];
            else if(j==a[i])dp[cur][j]+=i;
            dp[cur][j]%=MODN;
        }
        cout<<endl;
    }
    cout<<ans<<endl;
	return 0;
}

//无滚动
// #include <bits/stdc++.h>
// #define int long long 
// const int MODN=998244353;
// const int MAXN=3010;
// using namespace std;
 
// int dp[MAXN][MAXN];
// int32_t main(){
    // dp[0][0]=1;
    // int n,k;cin>>n>>k;
    // vector<int> arrmv(n+1);
    // for(int i=0;i<n;i++)cin>>arrmv[i+1];
    // vector<int> a=arrmv;
    // int ans=0;
    // for(int i=1;i<=n;i++){
        // if(k-a[i]>=0){
            // if(k-a[i]>0)ans+=dp[i-1][k-a[i]]*(n-i+1);
            // else ans+=i*(n-i+1);
                // ans%=MODN;
        // }
        // for(int j=k;j>=0;j--){
            // dp[i][j]+=dp[i-1][j];
            // if(j-a[i]>0)dp[i][j]+=dp[i-1][j-a[i]];
            // else if(j==a[i])dp[i][j]+=i;
            // dp[i][j]%=MODN;
            // cout<<dp[i][j]<<" ";
        // }
        // cout<<endl;
    // }
    // cout<<ans<<endl;
	// return 0;
// }