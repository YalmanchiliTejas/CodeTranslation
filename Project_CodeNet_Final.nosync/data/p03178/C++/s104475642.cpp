#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

ll dp[100010][3][101];

int main(){
    string s;int d;
    cin >> s >>  d;
    int n = s.length();

    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        int c = s[i] - '0';
        for (int j = 0; j < d; j++) {
            for (int ki = 0; ki < 10; ki++) {
                (dp[i + 1][1][(j+ki)%d] += dp[i][1][j])%=MOD;
            }
            for (int ki = 0; ki < c; ki++) {
                (dp[i + 1][1][(j+ki)%d] += dp[i][0][j])%=MOD;
            }
            (dp[i + 1][0][(j+c)%d] += dp[i][0][j])%=MOD;
        }
    }
    cout << (dp[n][1][0]+dp[n][0][0]-1+MOD)% MOD << endl;
    return 0;
}
