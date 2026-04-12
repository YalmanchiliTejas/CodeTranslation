#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back
const int mod = 1e9+7;

ll dp[1005][1005], C[1005][1005];
ll f1[1005], f2[1005];
ll pw(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2 == 1) ans = ans*a%mod;
        a = a*a%mod;
        b/=2;
    }
    return ans;
}
int main(){
    C[0][0] = 1;
    f1[0] = f2[0] = 1;
    for(int i=1;i<=1000;i++){
        C[i][0] = C[i][i] = 1;
        f1[i] = f1[i-1]*1ll*i%mod;
        f2[i] = pw(f1[i], mod-2);
        for(int j=1;j<i;j++) C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
    }
    int n, a, b, c, d;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    for(int j=a;j<=b;j++){
        dp[j-1][0] = 1;
        for(int i=n;i>=1;i--){
            dp[j][i] = (dp[j][i] + dp[j-1][i])%mod;
            int cnt = 0;
            ll inv = 1;
            for(int k=j;i+k-1<=n;k+=j){
                cnt++;
                inv = inv*f2[j]%mod;
                if(c <= cnt && cnt <= d){
                    ll res = dp[j-1][i-1]*1ll*C[n-i+1][k]%mod*f1[k]%mod*inv%mod*f2[cnt]%mod;
                    dp[j][i+k-1] = (dp[j][i+k-1] + res)%mod;
                }
            }
        }
    }
    printf("%d\n", dp[b][n]);
}