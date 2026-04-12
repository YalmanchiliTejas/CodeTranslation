#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int k, len, i;
    cin >> n >> k;
    len = n.length();
    long long dp0[len][4], dp1[len][4]; // 1がちょうど
    int top = n.at(0) - '0';

    dp0[0][0] = 1;
    dp0[0][1] = top - 1;
    dp0[0][2] = 0;
    dp0[0][3] = 0;
    for(i = 0; i < len; i++) dp1[i][0] = 0;
    dp1[0][1] = 1;
    dp1[0][2] = 0;
    dp1[0][3] = 0;

    for(i = 1; i < len; i++){
        int j;
        top = n.at(i) - '0';
        dp0[i][0] = 1;
        for(j = 1; j <= k; j++){
            dp0[i][j] = dp0[i-1][j-1] * 9 + dp0[i-1][j];
            if(top != 0){
                dp0[i][j] += dp1[i-1][j-1] * (top-1);
                dp0[i][j] += dp1[i-1][j];
            }
        }
        dp1[i][1] = dp1[i-1][1] && (top == 0);
        dp1[i][2] = (dp1[i-1][1] && (top != 0)) || (dp1[i-1][2] && (top == 0));
        dp1[i][3] = (dp1[i-1][2] && (top != 0)) || (dp1[i-1][3] && (top == 0));
    }

    cout << dp0[len-1][k] + dp1[len-1][k]<< endl;
}