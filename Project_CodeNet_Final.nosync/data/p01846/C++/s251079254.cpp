#include <bits/stdc++.h>
using namespace std;
#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n)-1;i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(b)-1;i>=(a);--i)
#define ALL(a) a.begin(),a.end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
    if (a < b) { a = b; return true; }
    return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
    os << "{";
    int a = 0;
    for (auto &tp : mp) {
        if (a) os << ", ";
        a = 1;
        os << tp;
    }
    return os << "}";
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << ":" << p.second;
    return os;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);


    for (;;) {
        string s; cin >> s;
        if (s == "#") break;

        s += '/';
        vector<string> board;
        string row;
        REP(k, s.size()) {
            if (s[k] == '/') {
                board.push_back(row);
                row = "";
                continue;
            }
            if (s[k] == 'b') {
                row += 'b';
                continue;
            }
            REP(i, s[k] - '0') {
                row += '.';
            }
        }

        int a, b, c, d; cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        swap(board[a][b], board[c][d]);

        string ans;
        REP(i, board.size()) {
            int cnt = 0;
            REP(j, board[i].size()) {
                if (board[i][j] == 'b') {
                    if (cnt > 0) ans += to_string(cnt);
                    ans += 'b';
                    cnt = 0;
                } else {
                    ++cnt;
                }
            }
            if (cnt > 0) ans += to_string(cnt);
            if (i < SZ(board)-1) ans += '/';
        }
        cout << ans << endl;
    }


    return 0;
}

