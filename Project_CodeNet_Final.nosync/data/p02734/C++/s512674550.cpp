#include<iostream>
using namespace std;
int main(){
    const int MOD = 998244353;
    int n;
    int s;
    cin >> n >> s;
    int dp[s+1]{0};
    int ans = 0;
    while(n--){
        int a;
        cin >> a;
        dp[0] = (dp[0]+1)%MOD;
        for(int i=s-a;i>=0;--i){
            dp[i+a] = (dp[i+a]+dp[i]) % MOD;
        }
        ans = (ans + dp[s]) % MOD;
    }
    cout << ans << endl;
}
