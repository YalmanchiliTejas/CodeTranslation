#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

// 1~N の整数で、0でない数字がちょうどk個あるものの個数
// dp[i][j][k]
// i　:　確定している桁数（最大100桁）0~100
// j　:　0でない数字が何個あるか（条件) 0~3
// k　:　N未満(0)か否(1)か(smaller) 0~1

int dp[101][4][2];

int main() {
    string s; int k;
    cin >> s >> k;

    int n = s.size(); // 桁数
    vector<int> data(n); rep(i,n) data[i] = s[i] - '0'; // 各桁の数字
    dp[0][0][0] = 1; // 初期化　（0桁目に0があると考える)

    rep(i,n){
        rep(j,4){
            dp[i+1][j][1] += dp[i][j][1]; // smaller 0 →smaller
            if(j+1 < 4) dp[i+1][j+1][1] += dp[i][j][1] * 9; // smaller 1~9 →smaller
            if(data[i] > 0){
                dp[i+1][j][1] += dp[i][j][0]; // bigger 0 →smaller
                if(j+1 < 4){
                    dp[i+1][j+1][1] += dp[i][j][0] * (data[i] -1); // bigger 1~data[i]-1 →smaller
                    dp[i+1][j+1][0] += dp[i][j][0]; // bigger data[i] →bigger
                }
            }
            else{
                dp[i+1][j][0] += dp[i][j][0]; // bigger 0 →bigger
            }
        }
    } // DP遷移

    int ans = dp[n][k][0] + dp[n][k][1];
    cout << ans << endl;
}