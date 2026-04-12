#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int d;
string k;

void adm(int& a, int b){
    a = (a + b) % mod;
}

int main(){
    cin>>k>>d;
    int l = k.length();
    vector<vector<int>> dp(d, vector<int>(2));
    dp[(k[0] - '0')%d][0] = 1;
    for(int i = 0; i < k[0] - '0'; i++){
        dp[i%d][1]++;
    }
    for(int i = 1; i < l; i++){
        vector<vector<int>> ndp(d, vector<int>(2));
        for(int a = 0; a <= k[i] - '0'; a++){
            for(int r = 0; r < d; r++){
                adm(ndp[(r + a%d)%d][a < k[i] - '0'], dp[r][0]);
            }
        }
        for(int a = 0; a < 10; a++){
            for(int r = 0; r < d; r++){
                adm(ndp[(r + a%d)%d][1], dp[r][1]); 
            }
        }
        dp = ndp;
    }
    int res = ((dp[0][0] + dp[0][1])%mod - 1 + mod) % mod;
    cout<<res<<endl;
    return 0;
}