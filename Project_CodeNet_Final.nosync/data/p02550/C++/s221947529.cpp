#pragma region head
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vv = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrepi(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bit(n) (1LL << (n))
template <class T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = 1002003004;
const ll LINF = 1002003004005006007ll;
struct preprocess {
    preprocess() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} ____;
#pragma endregion head

#pragma region library
#pragma endregion library

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vll sum(m + 1), nxt(m + 1), cnt(m + 1);
    repi(i, 2, m) {
        ll now = i;
        ll tot = 0;
        int icnt = 0;
        while (now < m) {
            tot += now;
            now *= now;
            icnt++;
        }
        sum[i] = tot;
        nxt[i] = now % m;
        cnt[i] = icnt;
    }
    vll used(m + 1, -1);
    vll val(m + 1, -1);
    ll ans = 0;
    ll now = x;
    ll idx = 0;
    while (idx < n) {
        if (now == 0) break;
        if (now == 1) {
            ans += n - idx;
            break;
        }
        if (used[now] != -1 && idx + (idx - used[now]) <= n) {
            ll add = ans - val[now];
            ll loop = (n - idx) / (idx - used[now]);
            ll len = idx - used[now];
            idx += len * loop;
            ans += add * loop;
            continue;
        }
        if (idx + cnt[now] <= n) {
            used[now] = idx;
            val[now] = ans;
            ans += sum[now];
            idx += cnt[now];
            now = nxt[now];
        } else {
            while (idx < n) {
                ans += now;
                now *= now;
                idx++;
            }
        }
    }
    cout << ans << '\n';
}
