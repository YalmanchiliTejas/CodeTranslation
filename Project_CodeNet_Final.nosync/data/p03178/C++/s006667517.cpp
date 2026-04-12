#include <cstring>
#include <iostream>
#define M 1000000007
using namespace std;
int main() {
    string s; cin >> s;
    int d; cin >> d;
    long long dp[d][2] = {};
    int cur = 0, prev = 1, sum = 0;
    dp[0][prev] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int k = 0; k < d; k++) {
            dp[k][cur] = 0;
            for (int j = 0; j < 10; j++) {
                int k1 = k - j;
                if (k1 < 0) k1 = (k1 % d + d) % d;
                if (j <= s[i]-'0' || k1 != sum) dp[k][cur] += dp[k1][prev];
                else dp[k][cur] += dp[k1][prev] - 1;
            }
            dp[k][cur] %= M;
        }
        swap(cur, prev);
        sum += s[i] - '0';
        if (sum >= d) sum %= d;
    }
    cout << (dp[0][prev] - 1 + M) % M << endl;
}
