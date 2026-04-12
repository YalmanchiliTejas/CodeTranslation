#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    string k;   cin >> k;
    ll l_k = k.length();
    int d;  cin >> d;
    vector<vector<vector<ll> > > dp(k.length()+1, vector<vector<ll> >(2, vector<ll>(d, 0)));
    ll mod = 1e9+7;

    dp[0][0][0] = 1;

    for (int i = 0; i < l_k; i++) {
        for (int j = 0; j < d; j++) {
            for (int f = 0; f < 2; f++) {
                for (int l = 0; l < 10; l++) {
                    if (f || l < k[i]-'0')
                        dp[i+1][1][(j+l)%d] = (dp[i+1][1][(j+l)%d]+dp[i][f][j])%mod;
                    else if (l == k[i]-'0')
                        dp[i+1][0][(j+l)%d] = (dp[i+1][0][(j+l)%d]+dp[i][f][j])%mod;
                }
            }
        }
    }

    cout << (dp[l_k][1][0] + dp[l_k][0][0]-1+mod)%mod << endl;
    return 0;
}