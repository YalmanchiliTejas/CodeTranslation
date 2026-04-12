#include<bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back


const int N = 2e5 + 51 + 51, MOD = 1e9 + 7, mod = 998244353, INF = 3e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

//gp_hash_table<int, int> table;

int a[N], dp[3000][3000];
bool ok[3000][3000];

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (n % 2 == 1) dp[i][i] = -a[i];
        else dp[i][i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        int len = n - i, kof = 1;
        if (len % 2 == 0) kof = -1;

        for (int j = 0; j < n; j++) {
            if (i + j >= n) break;
            if (kof == -1) dp[j][i + j] = max(dp[j + 1][i + j] + a[j], dp[j][i + j - 1] + a[i + j]);
            else dp[j][i + j] = min(dp[j + 1][i + j] - a[j], dp[j][i + j - 1] - a[i + j]);
        }
    }
    cout << -dp[0][n - 1];
}
