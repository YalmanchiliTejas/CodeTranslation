#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using ld = long double;

#define st first
#define nd second

const int MAXN = 1e5 + 5, inf = 1e9;
const ll INF = 1e18, mod = 1e9 + 7;
const ld PI = 3.1415926535897932384626433832795;

int cnt[MAXN], a[MAXN];
ll dp[MAXN][2][105];
bool vis[MAXN], used[MAXN];

vector<int> G[MAXN];
vector<ll> V;
set<ll> S;
map<ll, int> M;
stack<ll> St;
queue<ll> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(13) << fixed;

    //////////////////////////////////////////
    //////////////////////////////////////////

    string s;
    ll d;
    cin >> s >> d;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }

    dp[0][1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < d; j++) {
            for (int dig = 0; dig < 10; dig++) {
                int k = (j + dig) % d;

                dp[i][0][k] = (dp[i][0][k] + dp[i - 1][0][j]) % mod;
                if (dig < a[i]) {
                    dp[i][0][k] = (dp[i][0][k] + dp[i - 1][1][j]) % mod;
                } else if (dig == a[i]) {
                    dp[i][1][k] = (dp[i][1][k] + dp[i - 1][1][j]) % mod;
                }

                /*dp[i][0][j] = (dp[i][0][j] + dp[i - 1][0][k]) % mod;
                if (dig < a[i]) {
                    dp[i][0][j] = (dp[i][0][j] + dp[i - 1][1][k]) % mod;
                } else if (dig == a[i]) {
                    dp[i][1][j] = (dp[i][1][j] + dp[i - 1][1][k]) % mod;
                }*/
            }
            //cout << dp[i][0][j] << " ";
        }
        //cout << "\n";
    }
    //cout << "\n";

    /*for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < d; j++) {
                cout << dp[i][k][j] << " ";
            }
            cout  << "\n";
        }
        cout << "\n";
    }*/

    cout << ((dp[n][0][0] + dp[n][1][0] - 1) % mod + mod) % mod<< "\n";
}
