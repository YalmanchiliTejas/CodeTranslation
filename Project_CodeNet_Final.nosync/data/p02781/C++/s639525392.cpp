#include<bits/stdc++.h>
using namespace std;

enum State {
    EQUAL, LOWER, STATE_NUM
};

int64_t K;
string N;

vector<vector<vector<int64_t>>> memo;

//左からi桁目まで見た時、0でない数字がj個であり、Nに対する大小関係がsである場合の数
int64_t solve(int64_t i, int64_t j, State s) {
    if (i == N.size()) {
        return j == K;
    }

    if (j > K) {
        return 0;
    }

    if (memo[i][j][s] != -1) {
        return memo[i][j][s];
    }

    if (s == EQUAL) {
        //この桁をNと等しくする
        int64_t eq = solve(i + 1, j + (N[i] != '0'), EQUAL);

        //この桁をNとは異なるようにする
        int64_t lo = 0;
        for (int64_t d = 0; d < N[i] - '0'; d++) {
            lo += solve(i + 1, j + (d != 0), LOWER);
        }

        return memo[i][j][s] = eq + lo;
    } else if (s == LOWER) {
        int64_t result = 0;
        for (int64_t d = 0; d < 10; d++) {
            result += solve(i + 1, j + (d != 0), LOWER);
        }

        return memo[i][j][s] = result;
    }
}

int main() {
    cin >> N >> K;
    memo.resize(N.size() + 1, vector<vector<int64_t>>(K + 1, vector<int64_t>(STATE_NUM, -1)));
    cout << solve(0, 0, EQUAL) << endl;
}