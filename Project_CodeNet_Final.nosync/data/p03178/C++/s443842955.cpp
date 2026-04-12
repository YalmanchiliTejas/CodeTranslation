#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> a;

    {
        string tmp;
        cin >> tmp;
        
        a.resize(tmp.size());

        for (int i = 0; i < tmp.size(); i++) {
            a[i] = tmp[i] - '0';
        }
    }

    reverse(a.begin(), a.end());


    int n = a.size();

    int d;
    cin >> d;

    using ll = long long;
    const ll mod = 1000000007;

    static ll dp[100001][2][101];


    dp[n][1][0] = 1;

    for (int i = n; i > 0; --i) {
        for (int k = 0; k < d; k++) {
            for (int t = 0; t < 10; t++) {
                (dp[i - 1][0][(k + t) % d] += dp[i][0][k]) %= mod;
            }

            (dp[i - 1][1][(k + a[i - 1]) % d] += dp[i][1][k]) %= mod;

            for (int t = 0; t < a[i - 1]; t++) {
                (dp[i - 1][0][(k + t) % d] += dp[i][1][k]) %= mod;
            }
        }
    }

    cout << (dp[0][0][0] + dp[0][1][0] - 1 + mod) % mod << endl;
}
