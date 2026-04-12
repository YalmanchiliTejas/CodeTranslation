/// Great & Inimitable Vonatlus
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
     
#define x first
#define y second
#define pb push_back
#define sz(x) (int) x.size()
 
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;

using ll = long long;
using pii = pair<int, int>;                                   

const int N = 4e3;
const int MOD = 1e9 + 7;
const int INF32 = 1e9 + 1e2;

ll a[N], dp[N][N][2];

ll calc(int l, int r, bool h) {
    if (~dp[l][r][h])
        return dp[l][r][h];
    if (l > r)
        return 0;
    if (h)
        return dp[l][r][1] = min(calc(l + 1, r, 0) - a[l], calc(l, r - 1, 0) - a[r]);
    else
        return dp[l][r][0] = max(calc(l + 1, r, 1) + a[l], calc(l, r - 1, 1) + a[r]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];  
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j][0] = dp[i][j][1] = -1;
    cout << calc(1, n, 0);
    return 0;    
}