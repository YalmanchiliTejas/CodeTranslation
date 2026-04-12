#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define fi first
#define se second
#define int long long
#define mod 1000000007
#define rem 998244353
#define maxn 300005
const int INF = 1e18;
typedef pair<int, int> pii;


signed main() {
    boostIO;
    int n;
    cin >> n;
    int a[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum -= a[i];
        ans += (((a[i] % mod) * (sum % mod)) % mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
// XD ;;