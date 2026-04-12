#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
vector<long long> a(200200, 0);
long long dp[200200][2];
long long odddp[200200][2][2];

long long dpcheck(int limit) {
    dp[1][0] = a.at(0); dp[1][1] = a.at(1);
    for(int i = 1; i < limit; ++ i) {
        for(int j = 0; j < 2; ++j) {
            if(j == 0) chmax(dp[i+1][0], dp[i][j]+a.at(2*i));
            chmax(dp[i+1][1], dp[i][j]+a.at(2*i+1));
        }
    }
    return max(dp[limit][0], dp[limit][1]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a.at(i);
    for(int i = 0; i <= n; ++i) {
        dp[i][0] = -1e18;
        dp[i][1] = -1e18;
        odddp[i][0][0] = odddp[i][0][1] = odddp[i][1][0] = odddp[i][1][1] = -1e18;
    }

    int nlimit = n/2;
    if(n % 2 == 0) {
        cout << dpcheck(nlimit) << endl;
    }else {
        // 奇数かつ最後の要素を使うパターン
        odddp[1][0][0] = a.at(n-1)+a.at(0); odddp[1][1][0] = a.at(n-1)+a.at(1);
        odddp[1][0][1] = a.at(n-1);
        for(int i = 1; i < nlimit; ++i) {
            for(int j = 0; j < 2; ++j) {
                for(int k = 0; k < 2; ++k) {
                    if(k == 0) chmax(odddp[i+1][0][1], odddp[i][j][k]);
                    if(j == 0) chmax(odddp[i+1][0][k], odddp[i][j][k]+a.at(2*i));
                    if(i != nlimit-1) chmax(odddp[i+1][1][k], odddp[i][j][k]+a.at(2*i+1));
                }
            }
        }
        cout << max({dpcheck(nlimit), odddp[nlimit][0][1], odddp[nlimit][1][1]}) << endl;
    }
}