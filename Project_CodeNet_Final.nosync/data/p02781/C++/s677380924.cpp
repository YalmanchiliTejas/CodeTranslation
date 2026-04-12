#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

vector<vector<ll>> dp1, dp2;

void solve(const string &S, const int slen, const int K) {
    for (int i = 0; i < slen; i++) {
        for (int j = 0; j < 110; j++) {
            int d = S[i + 1] - '0';

            // dp1
            {
                if (d == 0) {
                    dp1[i + 1][j] += dp1[i][j];
                } else {
                    dp1[i + 1][j + 1] += dp1[i][j];
                }

                for (int k = 0; k < d; k++) {
                    if (k == 0) {
                        dp2[i + 1][j] += dp1[i][j];
                    } else {
                        dp2[i + 1][j + 1] += dp1[i][j];
                    }
                }

            }

            // dp2
            {
                for (int k = 0; k < 10; k++) {
                    if (k == 0) {
                        dp2[i + 1][j] += dp2[i][j];
                    } else {
                        dp2[i + 1][j + 1] += dp2[i][j];
                    }
                }
            }
        }
    }
}

int main(void) {
    string S;
    int K;
    cin >> S >> K;
    int slen = (int) S.size();
    S = " " + S;

    dp1.resize(slen + 1, vector<ll>(110));
    dp2.resize(slen + 1, vector<ll>(110));
    dp1[0][0] = 1;

    solve(S, slen, K);

    // printf("dp1: \n");
    // for (int i = 0; i <= slen; i++) {
    //     for (int j = 0; j <= 3; j++) {
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // printf("dp2: \n");
    // for (int i = 0; i <= slen; i++) {
    //     for (int j = 0; j <= 3; j++) {
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp1[slen][K] + dp2[slen][K] << endl;

    return 0;
}
