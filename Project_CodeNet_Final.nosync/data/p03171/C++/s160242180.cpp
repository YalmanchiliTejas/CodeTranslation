#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define ld                 long double
#define ff                 first
#define ss                 second
#define P                 pair<int,int>
#define pb                 push_back
#define mod             1000000007
#define inf             1e18
#define endl            '\n'
const int N = 3005;//change it when needed
int n, X, Y;
int dp[N][N];
int a[N];
int f(int i, int j) {
    if (i > j)
        return 0;
    if (i == j) {
        return a[j];
    }
    if (i + 1 == j)
        return max(a[i], a[j]);
    int &ans = dp[i][j];
    if (ans != -1)return ans;
    int op1 = 0, op2 = 0;
    op1 = a[i] + min(f(i + 2, j), f(i + 1, j - 1));
    op2 = a[j] + min(f(i, j - 2), f(i + 1, j - 1));
    // cout << op1 << " " << op2 << endl;
    return ans = (max(op1, op2));
}
void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Y += a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    X = f(0, n - 1);
    Y = Y - X;
    cout << X - Y << endl;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}