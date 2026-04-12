#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

int main(){
    string K;   cin>>K;
    int d;  cin>>d;
    int n = K.size();
    vector<vector<vector<ll>>>dp(n+1, vector<vector<ll>>(2, vector<ll>(d)));
    dp[0][0][0] = 1;
    rep(i, n)   rep(j, 2)   rep(k, d){
        int l = j?9:K[i]-'0';
        rep(x, l+1){
            (dp[i+1][j || x < l][(k+x)%d] += dp[i][j][k]) %= mod;
        }
    }
    ll ans = 0;
    rep(j, 2)   (ans += dp[n][j][0]) %= mod;
    cout << (ans+mod-1)%mod << endl;
}
