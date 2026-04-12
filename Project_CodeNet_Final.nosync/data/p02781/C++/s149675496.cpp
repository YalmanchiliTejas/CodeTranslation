#pragma region cp-helper
#include <bits/stdc++.h>
using namespace std;
#define AC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define lll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vll vector<lll>
#define vvl vector<vl>
#define vii vector<ii>
#define all(a) a.begin(), a.end()
#define qsort(a) sort(all(a))
#define qsortd(a) sort(all(a), greater<>())
#define qsortf(a, f) sort(all(a), f)
#define pb(n) push_back(n)
#define eb(n) emplace_back(n)
#define pp(a, b) emplace_back(a, b)
#define umap unordered_map
#define uset unordered_set
#define nl '\n'
#define fileio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)
#define qmod %mod
#define pls int
#define give main()
const int mod = 1000000007;
#pragma endregion

const int N = 1e6+5;
string n;
ll k, dp[105][5][3];

ll f(ll i, ll j, bool maxi) {
    if (dp[i][j][maxi]) return dp[i][j][maxi];
    if (!j) return 1;
    if (i == n.size()) return 0;
    if (!maxi) return dp[i][j][maxi] = 9*f(i+1, j-1, 0) + f(i+1, j, 0);
    int digit = n[i] - '0';
    if (!digit) return dp[i][j][maxi] = f(i+1, j, 1);
    return dp[i][j][maxi] = (digit-1) * f(i+1, j-1, 0) + f(i+1, j-1, 1) + f(i+1, j, 0);
}

pls give {
    AC;
    cin >> n >> k;
    cout << f(0, k, 1) << nl;
}
