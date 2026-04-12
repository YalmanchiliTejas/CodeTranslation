#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

ll dp[10101][2][110];

int main(){
    string s; int d;
    cin >> s >> d;
    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < d; k++) {
                for (int l = 0; l <= (j ? 9 : x); l++) {
                    dp[i + 1][j || l < x][(k + l) % d] += dp[i][j][k];
                    dp[i + 1][j || l < x][(k + l) % d] %= mod;
                }
            }
        }
    }
    cout << ((dp[n][0][0] + dp[n][1][0] - 1) % mod + mod) % mod<< endl;
    return 0;
}
