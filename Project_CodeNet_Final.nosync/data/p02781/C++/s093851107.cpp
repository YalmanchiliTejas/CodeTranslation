#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    string n;
    cin >> n;;
    int k;
    cin >> k;
    int sz;
    sz = n.size();

    int dp[110][2][5] = {};
    //dp[i+1][j][k] i桁目まで　j=0ならn未満決定　0でない数がk個
    dp[0][1][0] = 1;

    for (int i = 0; i < sz; ++i) {
        int di = n[i] - '0';
        for (int j = 0; j <= 3; ++j) {
            if(di == 0){
                dp[i+1][1][j] += dp[i][1][j];
                dp[i+1][0][j] += dp[i][0][j];
                dp[i+1][0][j+1] += dp[i][0][j] * 9;
            }
            else{
                dp[i+1][1][j+1] += dp[i][1][j];
                dp[i+1][0][j] += dp[i][0][j] + dp[i][1][j];
                dp[i+1][0][j+1] += dp[i][0][j] * 9 + dp[i][1][j] * (di - 1);
            }
        }
    }
    cout << dp[sz][0][k] + dp[sz][1][k] << endl;
}