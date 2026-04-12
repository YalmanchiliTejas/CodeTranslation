#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x);
        }
        p = p >> 1;
        x = (x*x);
    }
    return res;
}

int n,k;
int a[3005];
ll dp[3005][3005][2];

ll solve(int left, int right, int turn) {
    if (left > right) {
        return 0;
    }
    if (dp[left][right][turn] != LLONG_MAX)
        return dp[left][right][turn];
    ll ans = turn?min(solve(left, right-1,!turn) - a[right], solve(left + 1, right, !turn) - a[left])
    :max(solve(left, right-1,!turn) + a[right], solve(left + 1, right, !turn) + a[left]);
    return dp[left][right][turn] = ans;
}

int main() {
    IO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 3005; i++) {
        for (int j = 0; j < 3005; j++) {
            dp[i][j][0] = LLONG_MAX, dp[i][j][1] = LLONG_MAX;
        }
    }
    cout << solve(0,n - 1,0);
    return 0;
}
