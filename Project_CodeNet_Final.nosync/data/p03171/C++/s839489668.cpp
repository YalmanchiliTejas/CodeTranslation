// failed to generate code

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())

vector<vector<ll>> dp(3001, vector<ll>(3001, -1));

ll n;
vector<ll> a(3001);

ll rec(ll i, ll j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return dp[i][j] = a[i];
    return dp[i][j] = max(a[i] - rec(i + 1, j), a[j] - rec(i, j - 1));
}

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    cout << rec(0, n - 1) << endl;
}
