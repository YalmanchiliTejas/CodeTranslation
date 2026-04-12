#include <bits/stdc++.h>
 
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}
 
void solve() {
    ll N, X, M;
    cin >> N >> X >> M;

    // M が小さい、かつ A_{n + 1} は A_n から一意に定まる→周期を求めれば良さそう
    vector<ll> flag(M, -1);
    ll now = X;
    ll ind = 0;
    ll sum = 0;
    while(flag[now] == -1) {
        flag[now] = ind;
        sum += now;
        now = now * now % M;
        ind++;
        if (ind == N) {
            cout << sum << endl;
            return;
        }
    }
    ll d = ind - flag[now];
    ll target = flag[now];

    sum = 0;
    now = X;
    for(ll i = 0; i < target; i++) {
        sum += now;
        now = now * now % M;
    }

    ll p = 0;
    for(ll i = 0; i < d; i++) {
        p += now;
        now = now * now % M;
    }

    ll ans = sum + (N - target) / d * p;
    for(ll i = 0; i < (N + d - target) % d; i++) {
        ans += now;
        now = now * now % M;
    }

    cout << ans << endl;
}

int main() {
    #ifdef LOCAL_ENV
    cin.exceptions(ios::failbit);
    #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    
    solve();
}