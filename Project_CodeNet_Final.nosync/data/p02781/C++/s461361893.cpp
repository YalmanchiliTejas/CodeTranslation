#include <bits/stdc++.h>


using namespace std;

#ifdef CLION
ifstream ifs("/home/kyuridenamida/CLionProjects/project/input.txt");
#define cin ifs
#define scanf DONT_USE_SCANF
#endif

string S;

long long dp[111][2][4];

long long dfs(int pos, int ub, int kk) {
    if (kk < 0) return 0;
    if (pos == S.size()) return kk == 0;

    if (dp[pos][ub][kk] != -1)
        return dp[pos][ub][kk];

    long long ans = 0;
    if (ub == 1) {
        for (int i = 0; i <= S[pos] - '0'; i++) {
            bool nub = i == S[pos] - '0';
            ans += dfs(pos + 1, nub, kk - (i != 0));
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            ans += dfs(pos + 1, 0, kk - (i != 0));
        }
    }
    return dp[pos][ub][kk] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> S;
    int K;
    cin >> K;

    cout << dfs(0, 1, K);

}