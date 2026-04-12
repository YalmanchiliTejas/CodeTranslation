#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

string s;
ll d, dp[100001][101][3];

ll cal(string s){
    int len = s.size();
    for (int x = 1; x <= 9; x++){
        if (x < s[0] - '0') dp[1][x%d][0]++;
        else if (x > s[0] - '0') dp[1][x%d][2]++;
        else dp[1][x%d][1]++;
    }
    for (int i = 1; i < len; i++){
        for (int b = 0; b < d; b++){
            for (int sta = 0; sta < 3; sta++){
                if (dp[i][b][sta] == 0) continue;
                ll cur = dp[i][b][sta];
                for (int x = 0; x <= 9; x++){
                    if (sta == 0 || sta == 2) 
                        (dp[i + 1][(b + x)%d][sta] += cur) %= MOD;
                    else{
                        if (x < s[i] - '0')
                            (dp[i + 1][(b + x)%d][0] += cur) %= MOD;
                        else if (x > s[i] - '0') 
                            (dp[i + 1][(b + x)%d][2] += cur) %= MOD;
                        else (dp[i + 1][(b + x)%d][1] += cur) %= MOD;
                    }
                }
                
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= len; i++){
        for (int sta = 0; sta < (i == len ? 2 : 3); sta++){
            ans = (ans + dp[i][0][sta]) % MOD;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> s >> d;
    
    cout << cal(s);
    
    return 0;
}
