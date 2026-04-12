#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////

ll dp[10010][2][110];
const ll mod = 1000000007;

int main() {
    string s; cin >> s;
    int d; cin >> d;

    int len = s.size();

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int i = 0; i < len; i++)
    {
        int p = s[i] - '0';
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < d; k++)
            {
                for (int l = 0; l <= (j ? 9 : p); l++)
                {
                    int nextk = (k+l)%d;
                    dp[i+1][j || (l<p)][nextk] += dp[i][j][k];
                    dp[i+1][j || (l<p)][nextk] %= mod;
                }
            }
        }
    }
    
    // 0が入るから1引く
    ll ans = (dp[len][1][0]+dp[len][0][0])%mod - 1;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;

    return 0;
}