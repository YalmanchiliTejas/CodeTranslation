#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) begin(a),end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

lli INF = 1e18;

vector<vector<lli>> dp;

vector<lli> val;

lli n;

bool valid(lli u, lli v) {
    return u >= 0 and u < n and v >= 0 and v < n and u <= v;
}

lli solve(lli u, lli v) {
    lli &ans = dp[u][v];
    if(ans != -1) return ans;
    if(u == v) return ans = val[u];
    if(u > v) return ans = 0;
    if(!valid(u + 1, v))
        return ans = val[v] - solve(u, v - 1);
    if(!valid(u, v - 1))
        return ans = val[u] - solve(u + 1, v);
    return ans = max(val[v] - solve(u, v - 1) , val[u] - solve(u + 1, v));
}

int main()
{   _
    cin >> n;
    dp.assign(n, vector<lli>(n, -1));
    val.resize(n); fore(i, 0, n) cin >> val[i];
    cout << solve(0, n - 1) << ENDL;
    ///fore(i, 0, n) { fore(j, 0, n) cout << dp[i][j] << ' '; cout << ENDL;}
    return 0;
}
