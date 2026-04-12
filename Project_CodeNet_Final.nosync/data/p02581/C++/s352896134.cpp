#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;

int dp[2005][2005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(3*n);
    rep(i, 3*n) cin >> a[i], a[i]--;
    auto upd = [&](int x, int y, int v) {
        chmax(dp[x][y], v);
        chmax(dp[y][x], v);
        chmax(dp[x][n], v);
        chmax(dp[n][x], v);
        chmax(dp[y][n], v);
        chmax(dp[n][y], v);
        chmax(dp[n][n], v);
    };
    rep(i, 2005) rep(j, 2005) {
        dp[i][j] = -INF;
    }
    upd(a[0], a[1], 0);
    int base = 0;
    rep(ti, n-1) {
        int x = a[ti*3+2];
        int y = a[ti*3+3];
        int z = a[ti*3+4];
        if (x==y && y==z) {
            base++;
            continue;
        }
        vector<tuple<int, int, int>> q;
        rep(ri, 3) {
            {
                rep(i, n) {
                    int now = dp[i][n];
                    if (y==z) chmax(now, dp[i][y]+1);
                    q.emplace_back(i, x, now);
                }
            }
            {
                int now = dp[n][n];
                chmax(now, dp[z][z]+1);
                q.emplace_back(x, y, now);
            }
            swap(x, y); swap(y, z);
        }
        for (auto e: q) {
            int e1, e2, e3;
            tie(e1, e2, e3) = e;
            upd(e1, e2, e3);
        }
    }
    int ans = dp[n][n];
    chmax(ans, dp[a.back()][a.back()]+1);
    ans += base;
    
    
    pr(ans);
    return 0;
}
