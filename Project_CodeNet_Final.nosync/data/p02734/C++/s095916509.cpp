
// Problem : F - Knapsack for All Segments
// Contest : AtCoder Beginner Contest 159
// URL : https://atcoder.jp/contests/abc159/tasks/abc159_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MOD 998244353

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int a[3000], dp[3001][3001][3] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, s;
    cin >> n >> s;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    dp[0][0][0] = 1;
    for (int i=0; i<n; i++)
        for (int j=0; j<=s; j++) {
            add(dp[i+1][j][0], dp[i][j][0]);
            add(dp[i+1][j][1], dp[i][j][0]);
            add(dp[i+1][j][1], dp[i][j][1]);
            add(dp[i+1][j][2], dp[i][j][0]);
            add(dp[i+1][j][2], dp[i][j][1]);
            add(dp[i+1][j][2], dp[i][j][2]);
            if (j + a[i] <= s) {
                add(dp[i+1][j+a[i]][1], dp[i][j][0]);
                add(dp[i+1][j+a[i]][1], dp[i][j][1]);
                add(dp[i+1][j+a[i]][2], dp[i][j][0]);
                add(dp[i+1][j+a[i]][2], dp[i][j][1]);
            }
        }
    
    cout << dp[n][s][2] << "\n";

    return 0;
}
