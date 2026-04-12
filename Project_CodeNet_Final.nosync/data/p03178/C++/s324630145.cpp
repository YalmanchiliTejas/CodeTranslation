#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll dp[11000][2][110];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int m;
    cin >> s >> m;

    int n = s.size();
    dp[0][0][0] = 1;

    for(int i = 0; i < n; ++i){
        int D = s[i] - '0';
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < m; ++k){
                for(int d = 0; d <= (j? 9: D); ++d){
                    dp[i+1][j||(d<D)][(k+d)%m] += dp[i][j][k];
                    dp[i+1][j||(d<D)][(k+d)%m] %= mod;
                }
            }
        }
    }


    cout << (dp[n][0][0] + dp[n][1][0] + mod - 1) % mod << endl;

    return 0;
}