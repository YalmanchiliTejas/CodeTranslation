#include "bits/stdc++.h"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define display(v) for (auto x : v) cout << x << ", "
#define print(x) cout << (#x) << " = [ ";display(x); cout << "]\n"
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ceel(x, y) ((x) / (y) + !((x) % (y) == 0))
#define ss second
#define ff first
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

void __print(int x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifdef INCLUDEWHENOFFLINE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int maxN = 3001;
ll dp[maxN][maxN]; // stores X - Y
ll arr[maxN];

ll compute (int i, int j, int cnt)
{
    ll ans = 0;
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (cnt % 2 == 0)
    {
        ans = arr[i] + compute(i + 1, j, cnt + 1);
        ans = max(ans, arr[j] + compute(i, j - 1, cnt + 1));
    }
    else
    {
        ans = -arr[i] + compute(i + 1, j, cnt + 1);
        ans = min(ans, -arr[j] + compute(i, j - 1, cnt + 1));
    }
    dp[i][j] = ans;
    return ans;
}

void solve()
{
    for (int i = 0; i < maxN; i++)
        for (int j = 0; j < maxN; j++)
            dp[i][j] = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = compute(0, n - 1, 0);
    cout << ans << endl;
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}