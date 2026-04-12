#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "]\n" : ", "); } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    string k;
    int d;
    cin >> k >> d;
    int n = k.size();
    vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(n,vector<ll>(d,0)));
    int w = k[0]-'0';
    for (int i = 0;i < w;++i) dp[0][0][i%d] += 1;
    dp[1][0][w%d] = 1;
    for (int i = 1;i < n;++i) {
        int x = k[i]-'0';
        for (int j = 0;j < d;++j) dp[1][i][(j+x)%d] += dp[1][i-1][j];
        for (int j = 0;j < d;++j) for (int l = 0;l < x;++l) {
            dp[0][i][(j+l)%d] += dp[1][i-1][j];
            dp[0][i][(j+l)%d] %= mod;
        }
        for (int j = 0;j < d;++j) for (int l = 0;l < 10;++l) {
            dp[0][i][(j+l)%d] += dp[0][i-1][j];
            dp[0][i][(j+l)%d] %= mod;
        }
    }
    cout << (dp[0][n-1][0]+dp[1][n-1][0]-1+mod*2)%mod << endl;
    return 0;
}