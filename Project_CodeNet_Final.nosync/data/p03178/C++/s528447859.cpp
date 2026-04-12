#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

string s;
int d;
int dp[10010][110][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> d;
    int n = s.size();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            for(int k = 0; k < 10; k++){
                (dp[i + 1][(j + k) % d][1] += dp[i][j][1]) %= mod;
                if(s[i] -'0' == k) (dp[i + 1][(j + k) % d][0] += dp[i][j][0]) %= mod;
                else if(s[i] - '0' > k) (dp[i + 1][(j + k) % d][1] += dp[i][j][0]) %= mod;
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][0][1] - 1 + mod) % mod << endl;
}