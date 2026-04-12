#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    string k;
    int d;
    cin >> k >> d;
    int n = k.size();
    vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(n+1,vector<ll>(d,0)));
    dp[1][0][0] = 1;
    for (int i = 0;i < n;++i) {
        int a = k[i]-'0';
        for (int j = 0;j < d;++j) dp[1][i+1][j] += dp[1][i][(j-a+d*10)%d];
        for (int j = 0;j < a;++j) for (int x = 0;x < d;++x)  dp[0][i+1][x] += dp[1][i][(x-j+d*10)%d];
        //if (i == 0) dp[0][1][0] = 0;
        for (int j = 0;j < d;++j) for (int x = 0;x < 10;++x) dp[0][i+1][j] += dp[0][i][(j-x+d*10)%d];
        for (int j = 0;j < d;++j) for (int x = 0;x < 2;++x) dp[x][i+1][j] %= mod;
    }
    cout << (dp[0][n][0]+dp[1][n][0]-1+mod)%mod << endl;
    return 0;
}