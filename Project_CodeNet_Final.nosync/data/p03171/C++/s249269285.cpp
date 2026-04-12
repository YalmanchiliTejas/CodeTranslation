#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3000 + 1;

int n;
ll a[ N ], DP[ N ][ N ][ 2 ];

ll dfs(int l = 1, int r = n, int turn = 0) {
    if( l > r ) return 0LL;
    ll &ret = DP[ l ][ r ][ turn ];
    if( ~ret ) return ret;

    if( turn == 0 ) {
        ret = -4e18;
        ret = max(ret, a[ l ] + dfs(l + 1, r, turn ^ 1));
        ret = max(ret, a[ r ] + dfs(l, r - 1, turn ^ 1));
    } else {
        ret = 4e18;
        ret = min(ret, -a[ l ] + dfs(l + 1, r, turn ^ 1));
        ret = min(ret, -a[ r ] + dfs(l, r - 1, turn ^ 1));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i += 1)
        cin >> a[ i ];

    memset(DP, -1, sizeof DP);
    cout << dfs() << '\n';

    return 0;
}
