#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
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
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

string s;
bool ok(string x) {
    if (sz(s) == sz(x)) {
        return x <= s;
    } else {
        return sz(x) < sz(s);
    }
}
int main() {
    int k;
    cin >> s >> k;
    int n = sz(s);
    if (k == 1) {
        int ans = 0;
        for (char d = '1'; d <= '9'; d++) {
            string now = "";
            now += d;
            rep(i, 110) {
                ans += ok(now);
                now += '0';
            }
        }
        cout << ans << endl;
    }
    if (k == 2) {
        int ans = 0;
        string now = "00";
        for (int len = 2; len < 110; len++) {
            for (char a = '1'; a <= '9'; a++) {
                now[0] = a;
                for (int pos = 1; pos < len; pos++) {
                    for (char b = '1'; b <= '9'; b++) {
                        now[pos] = b;
                        ans += ok(now);
                    }
                    now[pos] = '0';
                }
            }
            now += '0';
        }
        cout << ans << endl;
    }
    if (k == 3) {
        int len = sz(s);
        ll ans = (ll)(s[0] - '1') * (len - 1) * (len - 2) / 2 * 81;
        for (ll l = 3; l < len; l++) {
            ans += 9 * (l - 1) * (l - 2) / 2 * 81;
        }
        string now;
        rep(i, len) now += '0';
        now[0] = s[0];

        for (int pos1 = 1; pos1 < len; pos1++) {
            for (int pos2 = pos1 + 1; pos2 < len; pos2++) {
                for (char b = '1'; b <= '9'; b++) {
                    for (char c = '1'; c <= '9'; c++) {
                        now[pos1] = b;
                        now[pos2] = c;
                        ans += ok(now);
                        now[pos1] = '0';
                        now[pos2] = '0';
                    }
                }
            }
        }

        cout << ans << endl;
    }
}