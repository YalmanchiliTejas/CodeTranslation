#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    cin >> str;

    ll d;
    cin >> d;

    vector<vector<vector<ll>>> dp(str.size()+1,vector<vector<ll>>(d,vector<ll>(2,0)));

    dp[str.size()][0][1] = 1;

    for(int i = str.size()-1; i >= 0; i--){
        for(int j = 0; j < d; j++){
            for(int k = 0; k <= 9; k++){
                if(k < str[str.size() - i - 1] - '0' ){
                    dp[i][(j+k)%d][0] += (dp[i+1][j][0] + dp[i+1][j][1])%MOD;
                    dp[i][(j+k)%d][0] %= MOD;
                }else if(k > str[str.size() - i - 1] - '0'){
                    dp[i][(j+k)%d][0] += dp[i+1][j][0];
                    dp[i][(j+k)%d][0] %= MOD;
                }else{
                    dp[i][(j+(str[str.size() - i - 1] - '0'))%d][0] += dp[i+1][j][0];
                    dp[i][(j+(str[str.size() - i - 1] - '0'))%d][0] %= MOD;
                    dp[i][(j+(str[str.size() - i - 1] - '0'))%d][1] += dp[i+1][j][1];
                    dp[i][(j+(str[str.size() - i - 1] - '0'))%d][1] %= MOD;
                }
            }
        }
    }

    ll ans;

    cout << ((ans = dp[0][0][0] + dp[0][0][1] - 1) < 0 ? ans + MOD : ans)%MOD << endl;
    
    return 0;
}