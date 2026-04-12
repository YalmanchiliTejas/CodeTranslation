#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

/*
30
4

brute-force -> look one by one -> from 1 to 30 -> if the digit sum is multiple of 4, then add
O(K * log K)


dp[d] - how many ways to get to remainder is d

dp[0] is the ans

dp[d] - how many ways to get to digit_sum as d

*/


int add(int a, int b) {
    const int mod = 1e9+7;
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }
    return c;
}

int subtract(int a, int b) {
    const int mod = 1e9+7;
    int c = a - b;
    if (c < 0) {
        c += mod;
    }
    return c;
}

int main() {
    const int nax = 10123;
    char K[nax];
    int D;
    scanf("%s", K);
    scanf("%d", &D);
    int len = strlen(K);
    vector<vector<int>> dp(D, vector<int>(2));
    // dp[sum][smaller_already] - no. of ways to choose digits so far
    // such that digits sum % D = sum and smaller_already means if the number
    // is already less than K
    dp[0][0] = 1;
    
    for (int where = 0; where < len; where++) {
        vector<vector<int>> new_dp(D, vector<int>(2));
        for (int sum = 0; sum < D; sum++) {
            for (bool sm_already : {false, true}) {
                for (int digit = 0; digit < 10; digit++) {
                    if (digit > K[where] - '0' && !sm_already) {
                        break;
                    }
                    int new_sum = (sum + digit) % D;
                    bool smaller = sm_already || digit < (K[where] - '0');
                    new_dp[new_sum][smaller] = add(new_dp[new_sum][smaller], dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }
    
    int answer = add(dp[0][false], dp[0][true]);
    
    answer = subtract(answer, 1);
    
    printf("%d", answer);
    /*
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        if (digit_sum(i) % D == 0) {
            ans += 1;
        }
    }
    printf("%d", ans);
    */
    
}