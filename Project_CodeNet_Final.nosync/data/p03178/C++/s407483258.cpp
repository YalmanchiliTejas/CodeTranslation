#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ll;
typedef pair<ll, ll> pii;
#define X first
#define Y second
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
// change type to pair & use counter for multi-set
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

void fastInOut();
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 10000 + 5;

string k;
int d;
int dp[N][105][2]; // idx, mod sum, is_flipped

int solve(int i=0, int sum=0, bool flip=0)
{
    if(i == k.size()) return (sum == 0);
    int &res = dp[i][sum][flip];
    if(~res) return res;
    res = 0;
    if(flip) {
        for(int j=0; j<10; ++j)
            res = (res + solve(i+1, (sum+j)%d, true)) % MOD;
    } else {
        res += solve(i+1, (sum+k[i]-'0')%d, false);
        for(int j=0; j<(k[i]-'0'); ++j)
            res = (res + solve(i+1, (sum+j)%d, true)) % MOD;
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    memset(dp, -1, sizeof(dp));
    cin >> k >> d;
    cout << (solve()-1+MOD)%MOD << '\n';
    return 0;
}

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
