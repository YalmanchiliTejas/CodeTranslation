#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;
typedef vector<vector<lint>> mat;

int main(){
    string k; int d; cin >> k >> d;
    int n = k.size();
    const lint mod = 1e9 + 7;
    lint dp[n+1][2][d];
    rep(i, n+1)rep(j, 2)rep(k, d) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i, n)rep(j, 2)rep(l, d){
        int x = j ? 9 : k[i] - '0';
        rep(m, x+1){
            dp[i+1][j || m < x][(l+m) % d] += dp[i][j][l];
            dp[i+1][j || m < x][(l+m) % d] %= mod;
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << endl;
}