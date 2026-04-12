#include "bits/stdc++.h"
#define ll long long
#define lld long double
#define MOD 998244353
#define inf 1000000000000000000LL
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll power(ll x,ll y, ll md=MOD){ll res = 1;x%=md;while(y){if(y&1)res = (res*x)%md;x *= x; if(x>=md) x %= md; y >>= 1;}return res;}
 
using namespace std;

#define endl '\n'
#define int ll

int dp[3001][3001];
int dp1[3001][3001];

signed main() {
    fast;

    int n,s;
    cin>>n>>s;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    dp[0][0] = 1;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=s;j++) dp[i][j] = dp[i-1][j];
        for(int j=0;j<=s;j++) {
            if(j-a[i-1]>=0) {
                dp[i][j] += dp[i-1][j-a[i-1]];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;

    for(int i=n;i>0;i--) {
        if(s-a[i-1]>0) {
            dp1[i-1][s-a[i-1]] += (n+1-i);
            dp1[i-1][s-a[i-1]] %= MOD;
        }
        else if(s-a[i-1]==0) {
            ans += (n+1-i)*(i);
            ans %= MOD;
        }

        for(int j=s-1;j>0;j--) {
            if(dp1[i][j]==0) continue;

            if(j-a[i-1]>0) {
                dp1[i-1][j-a[i-1]] += dp1[i][j];
                dp1[i-1][j-a[i-1]] %= MOD;
            }
            else if(j-a[i-1]==0) {
                ans += dp1[i][j]*(i);
                ans %= MOD;
            }

            dp1[i-1][j] += dp1[i][j];
            dp1[i-1][j] %= MOD;
        }
    }

    cout<<ans;

}