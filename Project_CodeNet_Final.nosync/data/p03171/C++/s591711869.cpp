#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

int n;
int dp[3010][3010];
int a[3010];

int calc(int l, int r){
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int turn = (l + n - 1 - r) % 2;
    int score = 0;
    if(turn == 0){
        score = max(calc(l + 1, r) + a[l], calc(l, r - 1) + a[r]);
    }else{
        score = min(calc(l + 1, r) - a[l], calc(l, r - 1) - a[r]);
    }
    return dp[l][r] = score;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) rep(j, 0, n) dp[i][j] = -1;
    cout << calc(0, n - 1) << endl;
}