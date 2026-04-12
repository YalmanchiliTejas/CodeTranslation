#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(obj) obj.begin(), obj.end()

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int iINF = 1e9;
const long long llINF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

long long dp[110][2][4];
string N;
int K;

long long rec(int i, int small, int non_zero) {
    if (non_zero > K) {
        return 0;
    }

    if (i == N.size()) {
        return non_zero == K;
    }

    if (dp[i][small][non_zero] != -1) {
        return dp[i][small][non_zero];
    }

    int lim = (small ? 9 : N[i] - '0');
    long long ret = 0;
    REP(next, lim + 1) {
        if (next == 0) {
            ret += rec(i + 1, small || N[i] - '0' > next, non_zero);
        } else {
            ret += rec(i + 1, small || N[i] - '0' > next, non_zero + 1);
        }
    }
    return dp[i][small][non_zero] = ret;
}

int main() {
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
    return 0;
}