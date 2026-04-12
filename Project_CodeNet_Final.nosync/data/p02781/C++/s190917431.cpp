#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    string n;
    int k;     cin >> n >> k;
    int l = n.length();
    vector<vector<vector<ll > > > dp(l+1, vector<vector<ll> >(2, vector<ll>(k+1, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < l; i++) {
        for (int s = 0; s < 2; s++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x <= (s ? 9 : n[i]-'0'); x++) {
                    if (j != k && x != 0) 
                        dp[i+1][s || x < n[i]-'0'][j+1] += dp[i][s][j];
                    else if (j != k && x == 0)
                        dp[i+1][s || x < n[i]-'0'][j] += dp[i][s][j];
                    else if (x == 0)
                        dp[i+1][s || x < n[i]-'0'][k] += dp[i][s][j];
                }
            }
        }
    }

    cout << dp[l][1][k] + dp[l][0][k] << endl;

    return 0;
}