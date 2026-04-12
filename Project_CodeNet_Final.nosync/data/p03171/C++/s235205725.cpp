
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ub              upper_bound
#define lb              lower_bound
#define isrt            insert
#define clr             clear
#define rsz             resize
#define ff              first
#define ss              second
#define lli             long long int
#define pb              push_back
#define pf              push_front
#define mkp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<int>
#define mii             map<lli,lli>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define INF             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(v)          v.begin(),v.end()
#define endl            "\n"


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

lli maxm(lli a, lli b)
{
    return (a >= b ? a : b);
}


lli minm(lli a, lli b)
{
    return (a <= b ? a : b);
}

lli power(lli x, lli y, lli p)
{
    lli res = 1;

    x = x % p;
    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

lli nCrmodp(lli n, lli r, lli p)
{
    if (r == 0)
        return 1;
    if (r == 1)
        return n;


    lli pro = 1, k = n;
    while (k > r)
    {
        pro *= k;
        pro %= p;
        --k;
    }

    k = 2;
    while (k <= (n - r))
    {
        pro *= power(k, (p - 2), p);
        pro %= p;
        ++k;
    }

    return pro;
}


string num_str(lli n, lli k)
{
    string str = "";
    lli x = n;
    while (x != 0)
    {
        string s = to_string(x % k);
        str = s + str;
        x /= k;
    }

    return str;
}


lli first_big(lli n, lli k, lli arr[])
{
    lli l = 0;
    lli r = n - 1;

    lli leftGreater = n;

    while (l <= r) {
        lli m = l + (r - l) / 2;

        if (arr[m] > k) {
            leftGreater = m;
            r = m - 1;
        }

        else
            l = m + 1;
    }

    return leftGreater;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

lli dp[3001][3001][2];
vector<int>v;

lli max_diff(lli i, lli j, lli t)
{
    if (dp[i][j][t] == INF)
    {
        if (i == j)
            dp[i][j][t] = v[i];
        else
        {
            if (t == 0)
                dp[i][j][t] = maxm(v[i] - max_diff(i + 1, j, 1), v[j] - max_diff(i, j - 1, 1));
            else
                dp[i][j][t] = maxm(v[i] - max_diff(i + 1, j, 0), v[j] - max_diff(i, j - 1, 0));
        }
    }
    return dp[i][j][t];

}


int main()
{
    c_p_c();

    int n;
    cin >> n;
    v.rsz(n + 1);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = INF;


    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    cout << max_diff(1, n, 0) << endl;

    return 0;
}