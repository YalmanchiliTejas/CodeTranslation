#include<bits/stdc++.h>
#define maxn 5050

using namespace std;
typedef long long ll;
ll dp[maxn][maxn],a[maxn],n;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int len=1;len<=n;len++){
        for (int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if ((n-len)&1) dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
            else dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
        }
    }
    cout << dp[1][n] << endl;
}
