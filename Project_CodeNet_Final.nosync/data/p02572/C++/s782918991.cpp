#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define it(a, x) for (auto &a : x)
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpii vector<pii>
#define vs vector<string>
#define gi greater<int>
#define vc vector<char>
#define vvi vector<vi>
#define vvc vector<vc>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define deb(x) cout << #x << "=" << x << endl;
#define in(i, n) for (auto i = 0; i < n; i++)
#define all(x) begin(x), end(x)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());//random shuffler

ll fxp(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll c = fxp(a, b / 2);
        return (c * c) % mod;
    }
    return (a * fxp(a, b - 1)) % mod;
}

void c_p_c() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(i, n)cin >> a[i];
    vector<ll> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    ll sum = pre[n - 1], ans = 0;
    in(i, n) {
        ans += (a[i] % mod) * ((sum - pre[i]) % mod);
        ans %= mod;
    }
    cout << ans;
}

int main(int argc, char const *argv[]) {
    c_p_c();
    solve();
    return 0;
}
