#pragma region cp-helper
#include <bits/stdc++.h>
using namespace std;
#define AC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
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
#define pls signed
#define give main()
const int mod = 1000000007;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#pragma endregion

const int N = 200005;

int n, arr[N], dp[N][3], vis[N][3];

int f(int pos, int skips) {
    if (pos == 0 and !skips) return arr[0];
    if (pos == 0) return max(0ll, arr[0]);
    if (pos < 0) return 0;
    if (vis[pos][skips]) return dp[pos][skips];
    vis[pos][skips] = 1; 
    if (!skips) return dp[pos][skips] = arr[pos] + f(pos-2, 0);
    else return dp[pos][skips] = max(arr[pos]+f(pos-2, skips), f(pos-1, skips-1));
}

pls give {
    AC;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << f(n-1, 1+(n%2)) << nl;
}