#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;

int64_t f[MAXN][4][2][2];
char N[MAXN];
int K;

int64_t dfs(int len, int nonZeroCount, bool started, bool sameWithN) {
    if (!len) {
        return nonZeroCount == K ? 1 : 0;
    }
    if (nonZeroCount > K) {
        return 0;
    }
    int64_t& now = f[len][nonZeroCount][started][sameWithN];
    if (~now) {
        return now;
    }
    now = 0;
    int upper = sameWithN ? N[len] - '0' : 9;
    for (int i = 0; i <= upper; ++i) {
        now += dfs(len - 1, nonZeroCount + (i != 0), started | (i != 0), sameWithN & (i == upper));
    }
    return now;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> (N + 1) >> K;
    memset(f, -1, sizeof(f));
    int len = strlen(N + 1);
    reverse(N + 1, N + 1 + len);
    cout << dfs(len, 0, false, true) << endl;
}