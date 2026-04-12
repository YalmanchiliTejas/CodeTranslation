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
    rep(i, 1, n+1) cin>>A[i];
    for (int l = 0; l < n; ++l)
        for(int i=1; i+l<=n; i++){
        j = i+l;
        if(i==j) dp[i][j] = A[i];
        else dp[i][j] = max(A[i]-dp[i+1][j], A[j]-dp[i][j-1]);
    }
    cout<<dp[1][n];
}