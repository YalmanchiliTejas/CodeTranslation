#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 3000+5;
ll a[maxn];
ll dp[maxn][maxn], sum[maxn];

ll dfs(int l,int r) {
    if(dp[l][r] || l == r) return dp[l][r];
    return dp[l][r] = max(a[l] - dfs(l + 1, r), a[r] - dfs(l, r - 1));
}

int main()
{
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
	  cin >> a[i];
	  dp[i][i] = a[i];
	}
        cout << dfs(1, n) << endl;
    return 0;
}
