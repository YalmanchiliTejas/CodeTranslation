#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back

const int N = 102;
const int mod = 1e9 + 7;

int32_t main(){
    string s;
    cin >> s;
    int d;
    cin >> d;
    int n = s.length();
    vector<vector<int>>dp(d,vector<int>(2,0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        vector<vector<int>>temp(d,vector<int>(2,0));
        for(int j=0;j<d;j++){
            for(int taken : {0,1}){
                for(int k=0;k<10;k++){
                    if(k > s[i]-'0' && !taken){
                        break;
                    }
                    temp[(j + k)%d][taken || (k < s[i]-'0')] += dp[j][taken];
                    temp[(j+k)%d][taken] %= mod;
                }
            }
        }
        dp = temp;
    }
    int ans = (dp[0][0] + dp[0][1])%mod;
    ans--;
    if(ans < 0){
        ans += mod;
    }
    cout<<ans<<endl;

}