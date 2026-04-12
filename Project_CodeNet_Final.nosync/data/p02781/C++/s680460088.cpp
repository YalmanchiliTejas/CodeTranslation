#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    string N; cin >> N;
    int K; cin >> K;
    int L = N.size();
    vector<vector<int>> dp0(L, vector<int>(K+1)), dp1(L, vector<int>(K+1));
    dp0[0][0] = 1;
    dp0[0][1] = (int)(N[0]-'0')-1;
    dp1[0][1] = 1;
    for (int i = 1; i < L; i++) {
        int tmp = (int)(N[i]-'0');
        for (int j = 0; j <= K; j++) {
            if (tmp != 0) {
                if (j) dp1[i][j] = dp1[i-1][j-1];
            }
            else {
                dp1[i][j] = dp1[i-1][j];
            }

            dp0[i][j] = dp0[i-1][j];
            if (tmp) {
                dp0[i][j] += dp1[i-1][j];
            }
            if (j) {
                dp0[i][j] += dp0[i-1][j-1]*9;
                if (tmp) {
                    dp0[i][j] += dp1[i-1][j-1]*(tmp-1);
                }
            }
        }
    }
    cout << dp0[L-1][K] + dp1[L-1][K] << endl;
}
