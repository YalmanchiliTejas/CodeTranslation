// Use the recursion hint

#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> values;


long long MINUS_INF = -1e15;

long long dp[3001][3001][2];

void init() {
    for (int i = 0; i <= 3000; i++)
        for (int j = 0; j <= 3000; j++)
            dp[i][j][0] = dp[i][j][1] = MINUS_INF;
}

long long makeMove(int start, int end, int move) {
    if (dp[start][end][move] != MINUS_INF) {
        return dp[start][end][move];
    }

    if (start > end) {
        return 0;
    } else {
        if (move == 1) {
            dp[start][end][move] = 
                max(values[start] + makeMove(start + 1, end, 0),
                    values[end] + makeMove(start, end - 1, 0));
        } else {
            dp[start][end][move] =
                min(-values[start] + makeMove(start + 1, end, 1),
                    -values[end] + makeMove(start, end - 1, 1));        
        }
    }

    return dp[start][end][move];
}

int main() {
    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    values.reserve(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    init();

    long long ans = makeMove(0, N - 1, 1);

    cout << ans << endl;

    return 0;
}
