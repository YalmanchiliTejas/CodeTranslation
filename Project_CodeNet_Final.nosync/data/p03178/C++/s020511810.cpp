#include <bits/stdc++.h>
#define fi first
#define se second 
#define ll long long 
#define mod 1000000007

using namespace std;

string s;
int n, k;
int dp[10100][110][2], dp2[10100][110], a[10100];

int main()   {
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;
    n = s.size();
    s = '+' + s;
    cin >> k;

    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';

    for (int i = 1; i < a[1]; i++)
        dp[1][i % k][0]++;
    dp[1][a[1] % k][1] = 1;

    for (int i = 1; i <= 9; i++)
        dp2[1][i % k]++; 

    int sum = (n > 1 ? dp2[1][0] : 0);
    for (int pos = 2; pos <= n; pos++) {
        for (int cif = 0; cif < 10; cif++) {
            for (int rest = 0; rest < k; rest++) {
                int nrest = (rest + cif) % k; 
                if (cif < a[pos]) {
                    dp[pos][nrest][0] = (dp[pos][nrest][0] + dp[pos - 1][rest][0] + dp[pos - 1][rest][1]) % mod;
                } else if (cif == a[pos]) {
                    dp[pos][nrest][0] = (dp[pos][nrest][0] + dp[pos - 1][rest][0]) % mod;
                    dp[pos][nrest][1] = (dp[pos][nrest][1] + dp[pos - 1][rest][1]) % mod;
                } else {
                    dp[pos][nrest][0] = (dp[pos][nrest][0] + dp[pos - 1][rest][0]) % mod;
                }

                dp2[pos][nrest] = (dp2[pos][nrest] + dp2[pos - 1][rest]) % mod;
            }
        }
        if (pos < n) 
            sum = (sum + dp2[pos][0]) % mod;
    }

    cout << ((dp[n][0][0] + dp[n][0][1]) % mod + sum) % mod;
    return 0;
}   