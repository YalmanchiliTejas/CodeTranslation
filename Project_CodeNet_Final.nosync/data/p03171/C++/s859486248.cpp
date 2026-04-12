//In The Name Of Godd
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define forr(i, n) for (ll i = n; i >= 0; i--)
#define fore(i, x, n) for (ll i = x; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 100000000000
#define eps 1e-9

const int maxn = 3010;
ll dp[maxn][maxn];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vi nms(n);
    forn(i, n) cin >> nms[i];
    forn(i, n) dp[i][i] = nms[i];
    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j < n; j++) {
            int l = j - i + 1, r = j;
            ll f = nms[l] - dp[l + 1][r], s = nms[r] - dp[l][r - 1];
            dp[l][r] = max(f, s);
        }
    }
    cout << dp[0][n - 1] << endl;
}
