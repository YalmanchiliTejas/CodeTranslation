#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
    string N;
    int K, l;
    cin >> N >> K;

    l = N.size();
    vector<int> n(l);
    rep(i,l) n[i] = N.at(i) - '0';

    vector<vector<Int>> dp0(l+1,vector<Int>(K+1, 0)), dp1(l+1,vector<Int>(K+1, 0));
    // dp0[i][j] : 上からi桁目まで決めて、0でない桁がj個、Nより必ず小さい、ようなものの個数
    // dp1[i][j] : 上からi桁目まで決めて、0でない桁がj個、Nより小さいかはまだ確定していない、ようなものの個数

    dp0[1][1] = n[0] - 1;
    dp1[1][1] = 1;
    dp0[1][0] = 1;

    rep1(i,l-1) rep(j,K+1) {
        if (n[i] != 0) {
            if (j > 0) dp0[i+1][j] = 9 * dp0[i][j-1] + dp0[i][j] + dp1[i][j-1] * (n[i] - 1) + dp1[i][j];
            else dp0[i+1][j] = dp0[i][j] + dp1[i][j];
        }
        else {
            if (j > 0) dp0[i+1][j] = 9 * dp0[i][j-1] + dp0[i][j];
            else dp0[i+1][j] = dp0[i][j];
        }

        if (n[i] != 0) {
            if (j > 0) dp1[i+1][j] = dp1[i][j-1];
        }
        else dp1[i+1][j] = dp1[i][j];

    }

    cout << dp0[l][K] + dp1[l][K] << endl;
}
