#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>

#define MAXN 3005
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

ll arr[MAXN];
ll dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

ll solve(int lo, int hi) {
    if(lo > hi) return 0LL;
    if(lo == hi) return arr[lo];
    if(vis[lo][hi]) return dp[lo][hi];
    dp[lo][hi] = max(arr[lo] - solve(lo + 1, hi),
                    arr[hi] - solve(lo, hi - 1));
    vis[lo][hi] = true;
    return dp[lo][hi];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(vis, false, sizeof(vis));

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << solve(1, n) << '\n';

    return 0;
}