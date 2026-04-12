#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cassert>

#define rep(i,x) for(int i = 0; i < x; i++)
#define rrep(i,x) for(int i = 1; i <= x; i++)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using ll = long long;
using namespace std;
const int INF = 1001001001;
const ll LINF = 1002003004005006007;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int extraX = n % 2 + 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(extraX + 2, -LINF));
    dp[0][0] = 0;
    rep(i, n){
        rep(j, extraX + 1){
            //最初はi % 2 = 0だが、extraXが入るたびに読み枠が1つずれる。
            if (i % 2 == j % 2) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
            else dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            //j(extraX)をインクリメントするなら、そこの枠を足さない
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
        }
    }
    cout << dp[n][extraX] << endl;
}
