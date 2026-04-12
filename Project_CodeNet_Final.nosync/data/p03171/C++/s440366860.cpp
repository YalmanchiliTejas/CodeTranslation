#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void dk()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int n;
int a[3000];
int gameeven()
{
    int dp[n][n];
    int i = 0, j = 1;
    while (j < n)
    {
        dp[i][j] = max(a[i], a[j]);
        i++;
        j++;
    }
    for (int p = 3; p < n; p = p + 2)
    {
        int ii = 0, jj = p;
        while (jj < n)
        {
            int k1 = dp[ii + 2][jj];
            int k2 = dp[ii + 1][jj - 1];
            int k3 = dp[ii][jj - 2];
            int a1 = min(k1, k2) + a[ii];
            int a2 = min(k2, k3) + a[jj];
            dp[ii][jj] = max(a1, a2);
            jj++;
            ii++;
        }
    }
    return dp[0][n - 1];
}
int gameodd()
{
    int dp[n][n];
    int i = 0, j = 0;
    while (j < n)
    {
        dp[i][j] = a[i];
        i++;
        j++;
    }
    for (int p = 2; p < n; p = p + 2)
    {
        int ii = 0, jj = p;
        while (jj < n)
        {
            int k1 = dp[ii + 2][jj];
            int k2 = dp[ii + 1][jj - 1];
            int k3 = dp[ii][jj - 2];
            int a1 = min(k1, k2) + a[ii];
            int a2 = min(k2, k3) + a[jj];
            dp[ii][jj] = max(a1, a2);
            jj++;
            ii++;
        }
    }
    return dp[0][n - 1];
}
int32_t main()
{
    //dk();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans;
    if (n % 2 == 0)
        ans = gameeven();
    else
        ans = gameodd();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    sum -= ans;
    cout << ans - sum;
    return 0;
}