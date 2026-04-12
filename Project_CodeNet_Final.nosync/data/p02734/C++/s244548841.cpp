#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef pair<int,int> pi;
typedef long long int ll;

const int N = (int)3e3+5;

ll dp[N][N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,s;
    cin>>n>>s;
    vector<int> a(n+1);
    //dp[0][0] = 1;
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        for(int j=0;j<=s;j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=a[i]) dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]])%mod;
        }
        dp[i][a[i]] = (dp[i][a[i]] + i)%mod;
        ans = (ans + dp[i][s])%mod;
    }
    cout<<ans;
}
