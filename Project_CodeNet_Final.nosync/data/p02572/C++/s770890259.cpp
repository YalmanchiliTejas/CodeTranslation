/*
Author: Vishesh Gupta
E mail: visheshguptavgr@gmail.com
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define newline ("\n")
#define deb(n) cerr << #n << " = " << (n) << '\n'
#define FOR(i, n) for (int(i) = 0; (i) < n; (i)++)
#define PI (3.141592653589)

#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(1);
    //start coding here

    int n;
    long long ans(0), sum(0);
    cin >> n;
    long long  arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum = (sum % MOD - arr[i] % MOD + MOD) % MOD;
        ans = ans + ((arr[i] % MOD) * (sum % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << newline;

    return 0;
}
