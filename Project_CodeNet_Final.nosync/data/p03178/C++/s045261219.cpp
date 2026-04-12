#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

string s;
ll n, d;
ll dp[10010][110][2];

ll add(ll a, ll b)
{
    return (a + b) % MOD;
}

int main()
{
    cin >> s >> d;
    n = s.size();
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 2; l++) {
                    if (l == 0 && k > s[i - 1] - '0') continue;
                    if (l == 0 && k < s[i - 1] - '0') dp[i][(j + k) % d][1] = add(dp[i][(j + k) % d][1], dp[i - 1][j][0]);
                    else dp[i][(j + k) % d][l] = add(dp[i][(j + k) % d][l], dp[i - 1][j][l]);
                }
            }
        }
    }

    ll sol = 0;
    sol = add(sol, dp[n][0][0]);
    sol = add(sol, dp[n][0][1]);
    if (sol == 0) cout << MOD - 1;
    else cout << sol - 1;



//    cout << "\n";
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < d; j++) {
//            for (int l = 0; l < 2; l++) {
//                cout << dp[i][j][l] << " ";
//            }
//            cout << " | ";
//        }
//        cout << "\n";
//    }
}
