#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    string N;
    cin >> N;
    int K;
    cin >> K;
    ll n = (ll)N.size();

    vector<int> keta, val;
    REP(i, n) {
        if (N[i] != '0') {
            keta.push_back(n - i - 1);
            val.push_back((int)(N[i] - '0'));
        }
    }
    REP(i, 3) {
        keta.push_back(0);
        val.push_back(0);
    }

    // debug
    // REP(i, 3) { cout << i << " " << keta[i] << " " << val[i] << endl; }

    ll ans = 0;
    REP(i, n - 1) {
        if (K == 1) {
            ans += 9;
        } else if (K == 2) {
            ans += 9 * 9 * i;
        } else if (K == 3) {
            ans += 9 * 9 * 9 * (i * (i - 1) / 2);
        }
        // cout << i << " " << ans << endl;  // debug
    }

    if (K == 1) {
        ans += val[0];
    } else if (K == 2) {
        ans += (val[0] - 1) * 9 * (n - 1);
        ans += val[1];
        ans += 9 * keta[1];
    } else if (K == 3) {
        ans += (val[0] - 1) * 9 * 9 * (n - 1) * (n - 2) / 2;
        ans += (val[1] - 1) * 9 * (keta[1]);
        ans += val[2];
        ans += 9 * keta[2];
        ans += 9 * 9 * (keta[1]) * ((keta[1]) - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
