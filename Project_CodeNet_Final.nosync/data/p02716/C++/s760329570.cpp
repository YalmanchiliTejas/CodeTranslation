#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define mod 1000000007
#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n"                   \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

int n;
vector<int> a;
map<pair<int, int>, int> dp;

int go(int ind, int left)
{
    if (left == 0)
        return 0;

    if (ind >= n || n - ind < left * 2 - 1)
        return -1e16;

    if (dp.find({ind, left}) != dp.end())
    {
        return dp[{ind, left}];
    }
    return dp[{ind, left}] = max(a[ind] + go(ind + 2, left - 1), go(ind + 1, left));
}

int32_t main()
{
    _
            cin >>
        n;
    a.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << go(0, n / 2);
    return 0;
}