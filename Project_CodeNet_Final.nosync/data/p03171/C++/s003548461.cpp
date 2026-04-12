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

const int MAXN = 3e3 + 5, inf = 1e9;
const ll INF = 1e18;
const ld PI = 3.1415926535897932384626433832795;

int cnt[MAXN];
ll dp[MAXN][MAXN][2], p[MAXN], a[MAXN];
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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i][0] = a[i];
    }

    for (int len = 1; len < n; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            if (dp[i + 1][j][1] + a[i] > dp[i][j - 1][1] + a[j]) {
                dp[i][j][0] = dp[i + 1][j][1] + a[i];
                dp[i][j][1] = dp[i + 1][j][0];
            } else {
                dp[i][j][0] = dp[i][j - 1][1] + a[j];
                dp[i][j][1] = dp[i][j - 1][0];
            }
        }
    }

    cout << dp[1][n][0] - dp[1][n][1] << "\n";
}
