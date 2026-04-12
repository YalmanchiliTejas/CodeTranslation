#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define each(i,a) for (auto&& i : a)
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    each(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    rep(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector< vector<T> >& vec) {
    rep(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s, s != "#") {
        vector<string> m(1, "");
        each(c, s) {
            if (isdigit(c)) {
                rep(i, '0', c) m.back() += ".";
            }
            else if (c == 'b') {
                m.back() += "b";
            }
            else {
                m.pb("");
            }
        }
        ll x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2; --y1, --x1, --y2, --x2;
        m[y2][x2] = 'b';
        m[y1][x1] = '.';
        string ans = "";
        rep(y, m.size()) {
            if (y) ans += "/";
            ll cnt = 0;
            each(c, m[y]) {
                if (c == 'b') {
                    if (cnt > 0) ans += char('0'+cnt);
                    cnt = 0;
                    ans += "b";
                }
                else {
                    ++cnt;
                }
            }
            if (cnt > 0) ans += char('0'+cnt);
        }
        cout << ans << endl;
    }
}