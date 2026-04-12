#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define debug(...) cout << "[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 1e4 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
string k;
int d;
ll dp[maxn][110][2];
ll solve(int i, int re, int f)
{
    if(i == sz(k)) return re == 0;
    if(dp[i][re][f] != -1) return dp[i][re][f];
    ll tot = 0;
    for(int j = 0; j < 10; j++)
    {
        if(f == 1 && (k[i] - '0') < j) break;
        int nf;
        if(f == 0 || (k[i] - '0') > j) nf = 0;
        else nf = 1;
        tot += solve(i + 1, (re + j) % d, nf);
        tot %= mod;
    }
    return dp[i][re][f] = tot;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> k >> d;
    memset(dp, -1, sizeof dp);
    cout << (solve(0, 0, 1) - 1 + mod) % mod<< "\n";
    return 0;
}
