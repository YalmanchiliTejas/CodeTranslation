#include <bits/stdc++.h>
#define IOS                 ios::sync_with_stdio(false); cin.tie(nullptr)
#define deb(x)              cout << #x << " = " << x << endl
#define deb2(x, y)          cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define f0(i, a, n)         for(i = a; i < n; i++)
#define f1(i, a, n)         for(i = a; i <= n; i++)
#define tc(t)               int t; cin >> t; while(t--)
#define ini(x, y)           memset(x, y, sizeof(x))
#define all(x)              x.begin(),x.end()
#define sz(x)               x.size()
#define ll                  long long int
#define vi                  vector<int>
#define si                  set<int>
#define pb                  emplace_back
#define ppb                 pop_back
#define mp                  make_pair
#define M                   1000000007
#define endl                '\n'
#define bits(x)             __builtin_popcountll(x)
#define zrbits(x)           __builtin_ctzll(x)

using namespace std;

void solve() {
        ll n, i;
        cin >> n;
        ll a[n];
        f0(i, 0, n) {
                cin >> a[i];
        }

        ll ans = 0;
        ll sum = 0;
        ll x;
        for(i = n-1; i >= 0; i--) {
                x = (a[i] * sum) % M;
                ans = (ans + x) % M;
                sum = (sum + a[i]) % M;
        }
        cout << ans << endl;
}

int main () {
        IOS;
        // tc(t)
        solve();
        return 0;
}