#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define isz(x) (int)(x).size()
#define watch(x) std::cerr << #x << " = " << x
#define watchsp(x) watch(x) << ' '
#define watchln(x) watch(x) << std::endl
#define cerr cerr && false && std::cerr
using vi = std::vector<int>;
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for (int i = 0; i < isz(vec); i++) {
        if (i > 0) os << ", ";
        os << vec[i];
    } 
    return os << "}";
}
const int mod = (int)1e9+7, NMAX = 10012;
int dp[NMAX][10][100];
std::string s;
int solve(int i, int want, const int d) {
    if (i < 0) return dp[0][0][want];
    int res = 0;
    for (char c = '0'; c < s[i]; c++) {
        res += dp[i+1][c-'0'][want];
        if (res >= mod) res -= mod;
    }
    watchln(i);
    watchln(want);
    watchln(res);
    // d - (curr + s[i]) == want
    want = (want - (s[i] - '0') + d * d * d) % d;
    res += solve(i-1, want, d);
    if (res >= mod) res -= mod;
    return res;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> s;
    std::reverse(all(s));
    int d; std::cin >> d;
    dp[0][0][0] = 1;
    for (int len = 1; len <= isz(s); len++) {
        for (int curr = 0; curr < 10; curr++) {
            for (int prev = 0; prev < 10; prev++) {
                for (int m = 0; m < d; m++) {
                    int nm = (m + curr) % d;
                    dp[len][curr][nm] += dp[len-1][prev][m];
                    if (dp[len][curr][nm] >= mod) {
                        dp[len][curr][nm] -= mod;
                    }
                }
            }
            watchsp(len); watchsp(curr);
            vi row(&dp[len][curr][0],&dp[len][curr][0]+d);
            watchln(row);
        }
    }
    int res = (solve(isz(s)-1,0,d)-1+mod) % mod;
    std::cout << res << std::endl;
    return 0;
}