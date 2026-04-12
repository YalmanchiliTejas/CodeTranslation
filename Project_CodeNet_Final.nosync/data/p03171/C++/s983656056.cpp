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

int rec (int l, int r, int who) {
    if (l > r) return 0;

    if (ok[l][r]) return dp[l][r];

    ok[l][r] = 1;

    if (!who) dp[l][r] = max(rec(l + 1,  r, 1) + a[l], rec(l, r - 1, 1) + a[r]);
    else dp[l][r] = min(rec(l + 1, r, 0) - a[l], rec(l, r - 1, 0) - a[r]);
    return dp[l][r];
}

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << rec(0, n - 1, 0);
}
