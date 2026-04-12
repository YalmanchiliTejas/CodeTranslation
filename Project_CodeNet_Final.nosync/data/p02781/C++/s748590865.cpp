#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<ll>> dp1;
vector<vector<ll>> dp2;

ll solve(const string S, const int slen, const int K) {
    for (int i = 0; i < slen; i++) {
        int d = S[i + 1] - '0';

        // dp1
        for (int j = 0; j <= K; j++) {
            if (j < K) {
                if (d > 0) {
                    dp1[i + 1][j + 1] += dp1[i][j];
                    dp2[i + 1][j + 1] += (d - 1) * dp1[i][j];
                    dp2[i + 1][j] += dp1[i][j];
                } else {
                    // actually d == 0
                    dp1[i + 1][j] += dp1[i][j];
                }
            } else {
                // actually j == k
                if (d > 0) {
                    dp2[i + 1][j] += dp1[i][j];
                } else {
                    // actually d == 0
                    dp1[i + 1][j] += dp1[i][j];
                }
            }
        }

        // dp2
        for (int j = 0; j <= K; j++) {
            // use numbers other than zero
            if (j < K) {
                dp2[i + 1][j + 1] += 9 * dp2[i][j];
            }

            // use zero
            dp2[i + 1][j] += dp2[i][j];
        }
    }

    return dp1[slen][K] + dp2[slen][K];
}

int main(void) {
    string S;
    cin >> S;
    int K;
    cin >> K;

    int len = (int) S.size();
    S = " " + S;

    dp1.resize(len + 1, vector<ll>(4, 0));
    dp2.resize(len + 1, vector<ll>(4, 0));
    dp1[0][0] = 1;

    cout << solve(S, len, K) << endl;

    // printf("dp1: \n");
    // for (int i = 0; i <= len; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // printf("dp2: \n");
    // for (int i = 0; i <= len; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    return 0;
}
