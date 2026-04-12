#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;


const int MOD = (int)1e9 + 7;



int main() {
    char str[10002];
    cin >> str;
    int d; cin >> d;
    int len = strlen(str);
    long long dp[len][d];

    int n = len;
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < d; ++j ) dp[i][j] = 0;
    }

    for(int i = 0; i < 10; ++i) dp[0][i%d] += 1;


    if(len == 1) {
        //
        long long ans = 0;
        for(int i = 1; i <= str[0] - '0'; ++i) {
            if(i%d == 0) ans += 1;
        }
        cout << ans ;
        return 0;
    }


    for(int i = 1; i < len; ++i) {
        int end = 10;
        if(i == len - 1) end = str[0] - '0';
        for(int j = 0; j < end; ++j) {
            for(int k = 0; k < d; ++k) {
                dp[i][(j+k)%d] +=  dp[i-1][k];
                dp[i][(j+k)%d] %= MOD;
            }

        }

    }


    int cc = str[0] - '0';
    for(int i = 1; i < len; ++i) {
        for(int j = 0; j < str[i] - '0'; ++j) {
            for(int k = 0; k < d; ++k) {
                if(i == len-1) {
                    dp[n-1][(cc + j)%d] += 1;
                    break;
                }
                dp[n-1][ (cc + (k + j) )%d ] += dp[len - 1 - (i+1)][k];

                dp[n-1][(cc + (k + j))%d] %= MOD;

            }  
        }
        cc += str[i] - '0';
        cc %= d;
    }
    if(cc%d == 0) {
        dp[n-1][0] += 1;
    }

    long long ans = dp[n-1][0];

    ans -= 1;

    cout <<(ans %MOD+ MOD)%MOD;
    

}