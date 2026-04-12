#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

ll dp[2][110][50];  /* dp[id][i+1][j] : 先頭からi桁目までで0でない数がj個現れるs以下の数の個数。
                                       ただし、id = 0 のとき現時点でsと等しい。
                                       id = 1 のとき現時点でsより小さいことが確定。 */

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    ll k;
    cin >> S >> k;
    ll n = S.size();

    dp[0][0][0] = 1;
    rep(id, 2){
        rep(i, n){
            rep(j, 4){
                ll lim = S[i]-'0';
                if(id) lim = 9;
                for(ll x = 0; x <= lim; x++){
                    dp[id || (x < lim)][i+1][j + (x != 0)] += dp[id][i][j];
                }
            }
        }
    }

    ll ans = 0;
    rep(id, 2){
        ans += dp[id][n][k];
    }
    cout << ans << endl;
    return 0;
}