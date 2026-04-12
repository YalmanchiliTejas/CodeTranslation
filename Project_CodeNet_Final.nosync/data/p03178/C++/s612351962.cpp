#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mod = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string k;
    cin >> k;
    int d;
    cin >> d;
    int l = k.size();
    vector< vector<int> > dp(d, vector<int>(2));
    dp[0][0] = 1;
    for(int i = 0; i < l; i++){
        vector< vector<int> > t(d, vector<int>(2));
        for(int j = 0; j < 2; j++){
            for(int digit = 0; digit <= 9; digit++){
                if(!j && k[i]-'0' < digit) break;
                for(int m = 0; m < d; m++){
                    if(digit < k[i]-'0'||j)t[(m+digit)%d][1]+=dp[m][j];
                    else t[(m+digit)%d][0]+=dp[m][j];
                    t[(m+digit)%d][0]%=mod;
                    t[(m+digit)%d][1]%=mod;
                }
            }
        }
        dp = t;
    }

    int ans = (dp[0][0] + dp[0][1])%mod;
    ans += mod-1;
    ans%=mod;
    cout << ans << endl;
}
