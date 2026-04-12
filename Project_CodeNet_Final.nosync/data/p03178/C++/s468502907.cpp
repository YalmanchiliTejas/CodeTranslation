#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
 
const int N = 2e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)1e18;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

inline int add(int a, int b){
    int ans = a + b;
    if(ans >= mod) ans -= mod;
    return ans; 
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    string s;
    cin >> s;
    int n = s.length();
    int d;
    cin >> d;
    vector< vector<int> > dp(2, vector<int>(d, 0));
    dp[1][0] = 1;

    for(int j = 0; j < n; j++){
        vector< vector<int> > new_dp(2, vector<int>(d, 0));
        for(int i = 0; i < d; i++){
            for(int cur = 0; cur <= 9; cur++){
                if((s[j] - '0') > cur){
                    new_dp[0][(i+cur)%d] = (new_dp[0][(i+cur)%d] + dp[0][i] + dp[1][i]) % mod;
                } 
                else if((s[j] - '0') == cur){
                    new_dp[1][(i+cur)%d] = (new_dp[1][(i+cur)%d] + dp[1][i]) % mod;
                    new_dp[0][(i+cur)%d] = (new_dp[0][(i+cur)%d] + dp[0][i]) % mod;
                }
                else{
                    new_dp[0][(i+cur)%d] = (new_dp[0][(i+cur)%d] + dp[0][i]) % mod;
                }
            }
        }
        dp = new_dp;
    }
    cout << (dp[0][0] + dp[1][0] - 1 + mod) % mod;
    return 0;
}
