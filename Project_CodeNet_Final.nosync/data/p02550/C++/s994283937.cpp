#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int oo = 1e9 + 5;
const LL ooll = (LL)1e18 + 5;
// const int MOD = 1e9 + 7;
const int MOD = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng)

clock_t start = clock();

const int N = 1e5 + 5;

int v[N], have[N];
void solve() {
    LL n;
    int x, m;
    cin >> n >> x >> m;
    for (int i=0;i<m;++i) have[i] = -1;
    v[0] = x;
    have[v[0]] = 0;
    int period = 0, st = -1;
    for (int i=1;i<N;++i) {
        v[i] = (v[i-1] * 1LL * v[i-1]) % m;
        if (have[v[i]] >= 0 && period == 0) {
            period = i - have[v[i]];
            st = have[v[i]];
            break;
        } 
        have[v[i]] = i;
    }
    // cout << st << " " << period << '\n';
    // return;
    if (n <= st) {
        LL ans = 0;
        for (int i=0;i<n;++i) ans += v[i];
        cout << ans << '\n';
        return;
    }
    LL once = 0, pre = 0, ans = 0;
    for (int i=st;i<st+period;++i) {
        once += v[i];
    }
    for (int i=0;i<st;++i) pre += v[i];
    int rem = (n - st) % period;
    for (int i=st;i<st+rem;++i) ans += v[i];
    ans += ((n - st) / period) * once;
    ans += pre;
    cout << ans << '\n';
}

int main() {
    FASTIO;
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
} 