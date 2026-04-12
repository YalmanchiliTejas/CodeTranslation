#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n, s;
    cin >> n >> s;
    int a[n];
    rep(i,n)cin >> a[i];
    ll MOD = 998244353;
    ll dp[n][3001];

    rep(i,n){
        rep(j,3001){
            if(i == 0){
                dp[i][j] = 0;
                if(j == 0) dp[i][j] = 2;
                if(j == a[i]) dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j];
                if(j == 0)dp[i][j]++;
                if(a[i] <= j) dp[i][j] += dp[i-1][j-a[i]];
                dp[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        ans += dp[i][s];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
 
 
