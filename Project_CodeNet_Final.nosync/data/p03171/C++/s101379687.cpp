#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

const int INF = 1LL << 40;
const int MOD = 1e9 + 7;
const int N = 3001;
int a[N], n;
int dp[N][N][2];

//f takes left, right, cur player and returns min x - y

int f(int l, int r, int p) {
    if(l == r)  
        return a[l];
    int &ans = dp[l][r][p];
    if(ans != -1) return ans;
    ans = max(a[l] - f(l + 1, r, 1 - p), a[r] - f(l, r - 1, 1 - p));
    return ans;
}

signed main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
    
    cout << f(1, n, 0) << endl;
    
    return 0;
}