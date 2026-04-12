#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep2(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define ALL(vec) vec.begin(), vec.end()
typedef long long ll;
typedef long double ld;

int binom(int64_t N, int64_t K) {
    if(K < 0 || N < K) return 0;
    int ret = 1;
    for(int i = 1; i <= K; ++i) {
        ret *= N--;
        ret /= i;
    }
    return ret;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    int l = s.size();
    reverse(ALL(s));

    vector<vector<ll>> dp(l, vector<ll>(k+1));
    dp[0][0] = 1;
    dp[0][1] = s[0] - '0';

    rep(i, l-1){
        dp[i+1][0] = 1;
        rep(j, k){
            int a = s[i+1] - '0';
            if(a > 0){
                dp[i+1][j+1] = dp[i][j] + (a - 1) * pow(9, j) * binom(i+1, j)
                                + pow(9, j+1) * binom(i+1, j+1);
            }
            else dp[i+1][j+1] = dp[i][j+1];
        }
    }
    cout << dp[l-1][k] << endl;
}