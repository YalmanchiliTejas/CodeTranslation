#include <bits/stdc++.h>
#define L "\n"
#define S " "
#define ll long long
#define pb push_back
#define mp make_pair
#define vi std::vector<int>
#define si std::set<int>
#define vl std::vector<long long>
#define qi std::queue<int>
#define de(a) cout << #a << "  ------>  " << a << "\n"
#define SIZE 3001
#define INF INT_MAX
#define FOR(i, n) for (i = 1; i <= n; i++)
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int a[SIZE];
ll dp[SIZE][SIZE][2];
bool flag[SIZE][SIZE][2];


ll f(int i, int j, int p)
{
    ll d1, d2;
    if(i == j){
        if(p == 1)  return dp[i][j][1] = a[i];
        else return dp[i][j][0] = -a[i];
    }
    flag[i][j][p] = 1;
    if (p == 1)
    {
        if(flag[i + 1][j][0]) d1 = dp[i + 1][j][0];
        else d1 = f(i + 1, j, 0);
        if(flag[i][j - 1][0]) d2 = dp[i][j - 1][0];
        else d2 = f(i, j - 1, 0);

        return dp[i][j][p] = max(d1 + a[i], d2 + a[j]);
    }
    else
    {
        if(flag[i + 1][j][1]) d1 = dp[i + 1][j][1];
        else d1 = f(i + 1, j, 1);
        if(flag[i][j - 1][1]) d2 = dp[i][j - 1][1];
        else d2 = f(i, j - 1, 1);

        return dp[i][j][p] = min(d1 - a[i], d2 - a[j]);
    }
}

void solve()
{
    int n, i;
    cin >> n;
    FOR(i, n)
    cin >> a[i];
    cout << f(1, n, 1) << L;
}
int main()
{
    FASTIO;
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    // #endif
    int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}