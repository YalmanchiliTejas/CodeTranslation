#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //gp_hash_table
#include <ext/pb_ds/tree_policy.hpp> // tree<int, null_type, less, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

#define hashmap gp_hash_table

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //find_by_order, order_of_key

const int N = (int) 3e3 + 10;
const int MOD = 998244353;

int n, S;
int a[N];
int memo[N][N][4];

int dp(int at, int S, int mask) {
    if(S < 0) return 0;
    if(at == n) return S == 0 && (mask == 0b11 || mask == 0b01);
    int& ans = memo[at][S][mask];
    if(ans != -1) return ans;
    ans = 0;
    if(mask == 0) {
        ans = (ans + dp(at, S, 0b01)) % MOD; //turn it on
        ans = (ans + dp(at + 1, S, mask)) % MOD; //keep it off
    } else if(mask == 0b01) { //can skip, take, or close it
        ans = (ans + dp(at + 1, S, mask)) % MOD; //skip
        ans = (ans + dp(at + 1, S - a[at], mask)) % MOD; //take
        ans = (ans + dp(at + 1, S, 0b11)) % MOD; //close
    } else { //closed, can only continue
        ans = (ans + dp(at + 1, S, mask)) % MOD;
    }
    return ans;
}

void solve() {
    cin >> n >> S;
    for(int i = 0; i < n; ++i) cin >> a[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, S, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    solve();
    cout.flush();
    return 0;
}