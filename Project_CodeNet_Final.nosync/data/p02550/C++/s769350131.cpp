#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define vin(v, N) vi v; rep(i, N) {int x; cin >> x; v.push_back(x);}
#define vout(v, N) rep(i, N) {cout << v[i] << " ";} cout << endl;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

const int MAX_N = 2e5 + 5;

void solve() {
    ll N, x, M;
    cin >> N >> x >> M;
    unordered_map<ll, ll> map;
    ll ans = x;
    map[x] = 0;
    for (ll i = 1; i < N; i++) {
        x = (x * x) % M;
        if (map.find(x) != map.end()) {
            ll n = i - map.find(x)->second;
            ll t = (N - i) / n;
            ll remain = (N - i) % n;
            ll s=0;
            rep(j, n) {
                if (j < remain) {
                    ans += x;
                }
                s += x;
                x = (x * x) % M;
            }
            ans += s * t;
            cout << ans;
            return;
        }
        map[x] = i;
        ans += x;
    }
    cout << ans;
}

//#define LOCAL 1

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();

    return 0;
}
