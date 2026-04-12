#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    string k;
    ll d;
    cin >> k >> d;
    ll n = k.size();

    ll dp[n+1][2][d]; memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    zep(i, 0, n){
        ll x = k[i]-'0';

        zep(y, 0, d){
            dp[i+1][0][(y+x)%d] += dp[i][0][y];
            dp[i+1][0][(y+x)%d] %= MOD;

            rep(j, 0, x-1){
                dp[i+1][1][(y+j)%d] += dp[i][0][y];
                dp[i+1][1][(y+j)%d] %= MOD;
            }

            rep(j, 0, 9){
                dp[i+1][1][(y+j)%d] += dp[i][1][y];
                dp[i+1][1][(y+j)%d] %= MOD;
            }
        }
    }
    print((dp[n][0][0]+dp[n][1][0]+MOD-1)%MOD)
    
    return 0;
}