#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){
    int k, d, n, i, j, smaller, x;
    string s;
    cin >> s >> k;
    n = s.length();
    ll dp[n+1][k+2][2] = {};
    dp[0][0][0] = 1;
    for(i=1; i<=n; i++){
        d = s[i-1] - '0';
        for(smaller=0; smaller<2; smaller++){
            for(j=0; j<=k; j++){
                for(x=0; x<=(smaller ? 9 : d); x++){
                    dp[i][j+(x!=0)][smaller || (x < d)] += dp[i-1][j][smaller];
                }
            }
        }
    }
    cout << dp[n][k][0] + dp[n][k][1];
    return 0;
}