#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int maxn=3e3+10;
const int mod=998244353;
const double eps=1e-6;

int n,s;
ll a[maxn],dp[maxn][maxn],ans;

int main() {
   // freopen("test.txt","r",stdin);
    cin>>n>>s;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=s;j++) {
            dp[i][j]=dp[i-1][j]%mod;
            if(a[i]<j) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
            else if(a[i]==j) dp[i][j]=(dp[i][j]+i)%mod;
        }
        ans=(ans+dp[i][s])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
