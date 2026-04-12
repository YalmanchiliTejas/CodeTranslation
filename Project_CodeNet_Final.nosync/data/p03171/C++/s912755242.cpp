#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int MAX_N = 3010;
int a[MAX_N];
bool cache[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N];

ll dfs(int i, int j){
    if (i == j) return dp[i][j]=a[i];
    if (cache[i][j]) return dp[i][j];
    dp[i][j] = max(a[i]-dfs(i+1, j), a[j]-dfs(i, j-1));
    cache[i][j] = 1;
    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) rep(j, n) dp[i][j] = 0, cache[i][j] = 0;
    dfs(0, n-1);
    cout << dp[0][n-1] << endl;

}