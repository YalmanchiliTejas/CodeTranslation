#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void add_self(int &a, int b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
}

const int EQUAL = 0;
const int LESSER = 1;
const int DMAX = 105;

int main(){
    int d;
    string s;
    cin >>s>> d; 
    
    int dp[2][DMAX], new_dp[2][DMAX];
    
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < d; ++j){
            dp[i][j] = 0;
            new_dp[i][j] = 0;
        }
    }
    
    int n = s.length();
    dp[EQUAL][0] = 1;
    for(int i = 0; i < n; ++i){
        int act_digit = s[i] - '0';
        for(int digit = 0; digit <= 9; ++digit){
            for(int prev_state = 0; prev_state < d; ++prev_state){
                int new_d = (prev_state + digit) % d;
                
                add_self(new_dp[LESSER][new_d], dp[LESSER][prev_state]);
                if(digit < act_digit){
                    add_self(new_dp[LESSER][new_d], dp[EQUAL][prev_state]);
                }else if(digit == act_digit){
                    add_self(new_dp[EQUAL][new_d], dp[EQUAL][prev_state]);  
                }
            }
        }
        
        for(int i = 0; i < d; ++i){
            dp[0][i] = new_dp[0][i];
            dp[1][i] = new_dp[1][i];
            new_dp[0][i] = 0;
            new_dp[1][i] = 0;
        }
    }
    
    int ans = dp[EQUAL][0];
    add_self(ans, dp[LESSER][0]);
    ans--;
    if(ans == -1){
        ans = MOD - 1;
    }
    cout << ans << "\n";
    
    return 0;
}