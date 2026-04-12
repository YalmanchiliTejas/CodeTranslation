#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <bitset>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////
const int magic = 998244353;

void add (int & a, int b) {
    a += b;
    if (a >= magic)
        a -= magic;
}

int mul (int a, int b) {
    return (int64)a * b % magic;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(S + 1, vector<int>(3)));

    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            add(dp[i+1][j][0], dp[i][j][0]); 

            add(dp[i+1][j][1], dp[i][j][0]);            
            add(dp[i+1][j][1], dp[i][j][1]);

            int nj = j + A[i];
            if (nj <= S) {
                add(dp[i+1][nj][1], dp[i][j][0]);
                add(dp[i+1][nj][1], dp[i][j][1]);
            }

            add(dp[i+1][j][2], dp[i][j][0]);
            add(dp[i+1][j][2], dp[i][j][1]);
            add(dp[i+1][j][2], dp[i][j][2]);

            if (nj <= S) {
                add(dp[i+1][nj][2], dp[i][j][0]);
                add(dp[i+1][nj][2], dp[i][j][1]);
            }

        }
    }

    cout << dp[N][S][2] << "\n";

    return 0;
}
