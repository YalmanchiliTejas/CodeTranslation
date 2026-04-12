#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

string s;
int k;
ll dp[110][2][5];

int main() {
    cin >> s >> k;
    int slen = s.length();

    dp[0][0][0] = 1;
    for(int i = 0; i < slen; ++i) {
        for(int j = 0; j <= k; ++j) {
            // i桁目まででsより小さいならi+1桁目は全部
            dp[i+1][1][j+1] += dp[i][1][j] * 9;
            // 追加しなかったとき
            dp[i+1][1][j] += dp[i][1][j];

            int check = s.at(i) - '0';
            // i桁目までは一緒だったが、i+1桁目を入れたら小さくなった
            if(check > 0) {
                dp[i+1][1][j+1] += dp[i][0][j] * (check-1);
                dp[i+1][1][j] += dp[i][0][j];
            }

            // i+1桁目もピンチケ
            if(check > 0) {
                dp[i+1][0][j+1] += dp[i][0][j];
            }else {
                dp[i+1][0][j] += dp[i][0][j];
            }
        }
    }

    cout << dp[slen][0][k] + dp[slen][1][k] << endl;
}