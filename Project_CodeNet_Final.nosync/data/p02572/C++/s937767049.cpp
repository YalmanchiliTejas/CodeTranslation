#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int inf = ~0u >> 1;
typedef pair<int, int> P;
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n)-1; i >= a; --i)
const ll mod = 1e9 + 7;
ll a[maxn];
ll sum[maxn];
int main() {
    IO;
    int n;
    cin >> n;
    REP(i, 1, n + 1) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 0;
    REP(i, 2, n + 1) {
        ans = (((a[i] % mod) * (sum[i - 1] % mod) % mod) + ans) % mod;
    }
    cout << ans % mod << endl;
    return 0;
}

