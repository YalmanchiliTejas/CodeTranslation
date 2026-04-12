#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
    for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
    for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 998244353;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.size() == 0) return os;
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    os << v[v.size() - 1];
    return os;
}

void solve() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<bool> memo(m, false);
    vector<ll> kazu;
    kazu.push_back(x);
    ll ans = x;
    memo[x] = true;
    ll now = x;
    ll per = 0, cum = x;
    ll prev_val = 0;
    bool flag = false;
    for (ll i = 0; i < n-1LL; ++i) {
        prev_val = now;
        now = (now*now % m);
        if (memo[now]) {
            flag = true;
            if (now == (now*now % m)) {
                cout << ans + now* (n - 1 - i) << endl;
                return;
            }
            break;
        } else {
            memo[now] = true;
        }
        cum += now;
        kazu.push_back(cum);
        ans += now;
        ++per;
    }
    if (!flag) {
        cout << ans << endl;
    } else {
        ll ans_2 = 0, now_2 = x, cnt_2 = 0;
        while (now_2 != now) {
            /* cout << now_2 << " " <<  (now_2*now_2 % m) << endl; */
            cnt_2++;
            ans_2 += now_2;
            now_2 = (now_2*now_2 % m);
        }
        ll rem = n - cnt_2, cumnum = now;
        vector<ll> kazu_2;
        kazu_2.push_back(now);
        now_2 = (now_2*now_2 % m);
        cnt_2 = 1;
        while (now_2 != now) {
            cnt_2++;
            cumnum += now_2;
            kazu_2.push_back(cumnum);
            now_2 = (now_2*now_2 % m);
        }
        ans_2 += (rem / cnt_2) * cumnum;
        if ((rem % cnt_2) > 0) {
            ans_2 += kazu_2[(rem % cnt_2 ) -1];
        }
        cout << ans_2 << endl;
    }
}


int main() {
    solve();
    char tmp;
    while (cin >> tmp) {
        cin.putback(tmp);
        solve();
    }
}

