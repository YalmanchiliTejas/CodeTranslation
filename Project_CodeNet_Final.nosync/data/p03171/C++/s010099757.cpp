#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define int long long
#define pb push_back
#define pencho ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 3005
#define mod 1000000007


int dp[N][N];
int a[N];

int solveDp(int index_1, int index_2) {
       if (index_1 > index_2)  return 0;
       if (dp[index_1][index_2] != -1)       return dp[index_1][index_2];

       dp[index_1][index_2] = max(a[index_1] - solveDp(index_1 + 1, index_2), a[index_2] - solveDp(index_1, index_2 - 1));
       return dp[index_1][index_2];
}

void solve() {
       pencho
       int n; cin >> n;
       for (int i = 0; i < n; i++) cin >> a[i];
       memset(dp, -1, sizeof(dp));
       for (int i = 0; i < n; i++) dp[i][i] = a[i];
       cout << solveDp(0, n - 1);
}


signed main()
{
#ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("o.txt", "w", stdout);
#endif

       solve();
}