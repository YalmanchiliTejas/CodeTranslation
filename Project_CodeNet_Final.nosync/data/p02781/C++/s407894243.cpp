#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
ll dp[1000][2][5]; //i 桁　ギリギリ攻めてるか　k個
int main()
{
    string n;
    cin >> n;
    int K;
    cin >> K;
    dp[0][0][0] = 0;
    dp[0][1][0] = 1;
    for (int i = 0; i < n.length(); i++)
    {
        rep(k, K)
        {
            int tmp = n[i] - '1';
            dp[i + 1][0][k] += dp[i][0][k];         //０を追加
            dp[i + 1][0][k + 1] += dp[i][0][k] * 9; // ０以外を追加
            if (n[i] != '0')
            {
                dp[i + 1][1][k + 1] += dp[i][1][k];       //ギリギリを追加
                dp[i + 1][0][k + 1] += dp[i][1][k] * tmp; //ギリギリ以外で0じゃない
                dp[i + 1][0][k] += dp[i][1][k];           //ギリギリ以外で0
            }
            else{
                dp[i + 1][1][k] += dp[i][1][k]; //ギリギリを追加
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n.length(); i++)
    {
        ans += dp[i][0][K];
        ans += dp[i][1][K];
    }
    cout << ans << endl;
    return 0;
}