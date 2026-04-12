#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 3050;
const long long INF = 1ll << 61;

vector <int> input;
int n;
lli dp[N][N];
bool vis[N][N];

lli solve(int i, int j) {
    if (j - i == 1) return n & 1 ? input[i] : -input[i];
    if (vis[i][j]) return dp[i][j];
    if ((n - j + i) & 1) {
        dp[i][j] = min(solve(i, j - 1) - input[j - 1], solve(i + 1, j) - input[i]);
    } else {
        dp[i][j] = max(solve(i, j - 1) + input[j - 1], solve(i + 1, j) + input[i]);
    }
    vis[i][j] = true;
    return dp[i][j];
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    input.resize(n);
    fop (i,0,n) cin >> input[i];
    fop (i,0,N) fop (j,0,N) {
        dp[i][j] = -INF;
        vis[i][j] = false;
    }
    cout << solve(0, n) << endl;
}