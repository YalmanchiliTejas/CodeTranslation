
/// time is tough.....so don't stop ...keep learning ...keep growing :)

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
const int N = 1e5+5 ;
const int K = 50 ;
const ll mod =  1e9+7 ;
#define pb push_back
#define ft first 
#define sd second 
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
ll poww(ll a,ll b){ll res=1;while(b){if(b&1){res*=a;}a=a*a;b>>=1;}return res;}
ll poww(ll a,ll b,ll mod){ll res=1;while(b){if(b&1){res*=a;res%=mod;}a=a*a;a%=mod;b>>=1;}return res;}
const int INF = 2e9 ;
int n, m, u, v, k;
ll dp[3005][3005];// pre[105][N];
ll a[3005];
ll f(int i, int j){
   
}
int main(){
    cin >> n ;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
   // memset(dp, -1, sizeof dp);
    for(int len = 1;len <= n; len++) {
        for(int st = 1; st + len -1 <= n; st++) {
            int en = st + len - 1;
            if(len % 2 == n % 2) dp[st][en] = max(dp[st + 1][en] + a[st], dp[st][en - 1] + a[en]);
            else dp[st][en] = min(dp[st + 1][en] - a[st], dp[st][en - 1] - a[en]);
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}
 