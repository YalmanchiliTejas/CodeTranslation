#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define pb emplace_back
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
const int N = 3e3+5, inf = 1e9+7;
int n, k, i, j;
int A[N], dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, a, b, ans = 0;
    cin>>n;
    rep(i, 1, n+1){
        cin>>A[i];
        sep(j, i, 0)
            dp[j][i] = max(A[j]-dp[j+1][i], A[i]-dp[j][i-1]);
    }
    cout<<dp[1][n];
}