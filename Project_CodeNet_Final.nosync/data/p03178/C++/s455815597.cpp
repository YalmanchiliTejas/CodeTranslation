#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define INF 1e18
#define x first
#define y second
string k;
const ll MOD = 1e9+7, a = 10007, b = 107, c = 2;
int mod;
ll dp[a][b][c];
void init(){
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int l = 0; l < c; ++l) {
                dp[i][j][l] = -1;
            }
        }
    }
}
ll solve(int index, int m, bool good)
{
    if(index == k.length()) {
        if(m%mod==0)
            return 1;
        else
            return 0;
    }
    if(dp[index][m][good] != -1)
        return dp[index][m][good];
    else{
        int last = int(k[index]) - 48;
        ll ans = 0;
        if(good) {
            for (int i = 0; i <= 9; ++i) {
                ans = (ans + solve(index + 1, (m + i) % mod, true)) % MOD;
            }
        }
        else{
            for (int i = 0; i < last; ++i) {
                ans = (ans + solve(index + 1, (m + i) % mod, true)) % MOD;
            }
            ans = (ans + solve(index + 1, (m + last) % mod, false)) % MOD;
        }
        return dp[index][m][good] = ans;
    }
}
int main() {
    fast;
    cin>>k>>mod;
    init();
    ll answer = solve(0, 0, false) - 1;
    if(answer < 0)
        answer += MOD;
    cout<<answer;
}