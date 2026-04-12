// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;

const ll INF = numeric_limits<ll>::max(),
         MOD = 1e9 + 7;

const int INF_i = numeric_limits<int>::max(),
          MAX = 1e6;

ll f(string &s, int D) {
    vll dp(D); // dp[j] = number of ways to get digit sum of a valid prefix % D = 0
    int prev = s[0] - '0';
    for (int d = 1; d < prev; d++) {
        dp[d % D] += 1;
    }

    prev %= D; // digit sum of prefix [0, i)
    for (int i = 1; i < s.size(); i++) {
        int di = s[i] - '0'; 
        vll new_dp(D);
        for (int d = 0; d < 10; d++) {
            if (d) (++new_dp[d % D]) %= MOD; // case '00000..0d'
            
            for (int j = 0; j < D; j++)
                (new_dp[(j + d) % D] += dp[j]) %= MOD;
            
            if (d < di) (++new_dp[(prev + d) % D]) %= MOD; // case 'd0d1d2..d(i-1)d'
        }
        swap(dp, new_dp);
        (prev += di) %= D;
    }
    if (!prev) (++dp[0]) %= MOD;
    return dp[0] % MOD;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int D;
    cin >> D;
    cout << f(s, D) << '\n';

}