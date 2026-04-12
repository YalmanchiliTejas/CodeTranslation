#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

const ll MOD = ll(1e9 + 7);

vector<vector<ll>> dp1;
vector<vector<ll>> dp2;

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();
    S = " " + S;

    int K;
    cin >> K;

    dp1.resize(slen + 1, vector<ll>(105, 0));
    dp2.resize(slen + 1, vector<ll>(105, 0));
    dp1[0][0] = 1;

    for (int i = 0; i < slen; i++) {
        int d = S[i + 1] - '0';

        for (int j = 0; j <= K; j++) {
            // dp1
            if (d == 0) {
                dp1[i + 1][j] = (dp1[i + 1][j] + dp1[i][j]) % MOD;
            } else {
                dp1[i + 1][j + 1] = (dp1[i + 1][j + 1] + dp1[i][j]) % MOD;
            }

            // dp2
            dp2[i + 1][j] = (dp2[i + 1][j] + dp2[i][j]) % MOD; // when use 0

            dp2[i + 1][j + 1] = (dp2[i + 1][j + 1] + 9 * dp2[i][j]) % MOD; // when use other than 0
            // printf("i: %d, j: %d, dp2[i][j]: %lld, dp2[i + 1][j + 1]: %lld\n", i, j, dp2[i][j], dp2[i + 1][j + 1]);

            if (d != 0) {
                dp2[i + 1][j] = (dp2[i + 1][j] + dp1[i][j]) % MOD; // when use 0.
            }

            for (int k = 1; k < d; k++) {
                dp2[i + 1][j + 1] = (dp2[i + 1][j + 1] + dp1[i][j]) % MOD; // when use other than 0
            }
        }
    }

    cout << dp1[slen][K] + dp2[slen][K] << endl;

    // printf("dp1: \n");
    // for (int i = 0; i <= slen; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // printf("dp2: \n");
    // for (int i = 0; i <= slen; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    return 0;
}
