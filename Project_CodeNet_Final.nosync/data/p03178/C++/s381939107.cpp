#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;
const int MOD = 1e9+7;

int main(){
    string k;
    ll d; 
    cin >> k >> d;
    int w = (int)k.length();
    vector<int> keta;
    for(int i=0; i<w; i++){
        keta.push_back((int)k[i] - 48);
    }
    vector<vector<vector<ll>>> dp(d, vector<vector<ll>>(w, vector<ll>(2, 0)));
    for(int i=0; i<w; i++){
        if(i==0){
            for(int j=0; j<keta[0]; j++){
                dp[j % d][0][1] += 1;
            }
            dp[keta[0] % d][0][0] += 1;
            continue;
        }
        for(int j=0; j<d; j++){
            for(int k=0; k<10; k++){
                dp[(j+k)%d][i][1] += dp[j][i-1][1];
                if(k < keta[i]){
                    dp[(j+k)%d][i][1] += dp[j][i-1][0];
                }
            }
            dp[(j + keta[i]) % d][i][0] += dp[j][i-1][0];
            dp[j][i][1] %= MOD;
        }
    }
    // for(int i=0; i<2; i++){
    //     for(int j=0; j<w; j++){
    //         for(int k=0; k<d; k++){
    //             cout << dp[k][j][i] << " ";
    //         }
    //         cout <<"\n";
    //     }
    //     cout << "\n";
    // }
    cout << (dp[0][w-1][0] + dp[0][w-1][1] - 1) % MOD << "\n";
    return 0;
}