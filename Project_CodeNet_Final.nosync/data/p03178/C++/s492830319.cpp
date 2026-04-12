#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin >> S;
    int D; cin >> D;
    S = '0' + S;
    int lenS = S.length();
    ll dp[lenS][D][2]{};
    dp[0][0][0] = 1;
    for(int i = 0; i < lenS-1; i++){
        int keta = S[i+1]-'0';
        for(int j = 0; j < D; j++){
            for(int smaller = 0; smaller <= 1; smaller++){
                for(int d = 0; d <= (smaller ? 9 : keta); d++){
                    dp[i+1][(j+d) % D][smaller || d<keta] += dp[i][j][smaller];
                    dp[i+1][(j+d) % D][smaller || d<keta] %= mod;
                }
            }
        }
    }
    ll ans = dp[lenS-1][0][0] + dp[lenS-1][0][1] - 1;
    if(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}