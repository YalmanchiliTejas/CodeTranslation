#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int nax = 10123;
char k[nax];

void add_self(int &a, int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}

int main(){
    int d;
    scanf("%s", k);
    cin >> d;
    int len = strlen(k);
    vector<vector<int>>dp(d, vector<int>(2));
     dp[0][0] = 1;
    for(int i=0; i<len; i++){
        vector<vector<int>>new_dp(d, vector<int>(2));
        for(int j=0; j<d; j++){
            for(bool f: {false, true}){
                for(int a=0; a<10; a++){
                    if(a > k[i]-'0' && !f)
                    {
                        break;
                    }
                        
                    add_self(new_dp[(j+a)% d][f || (a<k[i]-'0')], dp[j][f]);
                }
            }
        }
        dp = new_dp;
    }
    int ans = (dp[0][true] + dp[0][false])%mod;
    --ans;
    if(ans == -1){
        ans = mod-1;
    }
    cout << ans;
    return 0;
}