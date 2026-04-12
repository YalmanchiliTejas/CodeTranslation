#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
const ll mod = 998244353;
const ll maxn = 3005;
ll dp[maxn][maxn][2];
// #define debug
int main(){
    ll n, s;
    cin >> n >> s;
    vector<ll> num;
    for(ll i = 0; i < n; ++i){
        ll c;
        cin >> c;
        num.push_back(c);
    }
    ll ans = 0;
    for(ll i = 0; i <= s; ++i){
        dp[0][i][0] = dp[0][i][1] = 0;
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][num[0]][0] = dp[0][num[0]][1] = 1;
    for(ll i = 1; i < n; ++i){
        ll cur_num = num[i];
        for(ll j = 0; j <= s; ++j){
            ll a = dp[i - 1][j][0];
            ll b_1 = dp[i - 1][j][1];
            ll b_2;
            if(j < cur_num){
                b_2 = 0;
            }
            else if(j > cur_num){
                b_2 = dp[i - 1][j - cur_num][1];
            }
            else{
                b_2 = i + 1;
            }
            dp[i][j][0] = (a + b_1 + b_2) % mod;
            dp[i][j][1] = (b_2 + b_1) % mod;
        }
    }
    #ifdef debug
        for(int i = 0; i < n; ++i){
            cout << "i = " << i << endl;
            for(int j = 0; j <= s; ++j){
                cout << " " << "j = " << j << endl;
                cout << "  " << dp[i][j][0] << " " << dp[i][j][1] << endl;
            }
        }
    #endif
    cout << dp[n - 1][s][0] << endl;
    return 0;
}