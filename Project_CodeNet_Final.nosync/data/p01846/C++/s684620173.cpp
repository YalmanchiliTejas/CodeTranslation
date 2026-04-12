#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); }
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return 1;} return 0; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl

// gcc拡張マクロ
#define gcd __gcd
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール
string jfenize(const string &row) {
    string result = "";
    ll stack = 0;
    REP(i, row.size()) {
        if (row[i] == 'b') {
            if (stack) result += to_string(stack);
            result += 'b';
            stack = 0;
        } else {
            stack++;
        }
    }
    if (stack) result += to_string(stack);
    return result;
}
string parse(const string &jfen) {
    string result = "";
    REP(i, jfen.size()) {
        if ('1' <= jfen[i] && jfen[i] <= '9') {
            result += string(jfen[i] - '0', '.');
        } else if (jfen[i] == 'b') {
            result += 'b';
        }
    }
    return result;
}
vector<string> split(const string &s) {
    vector<string> result;
    string stack = "";
    REP(i, s.size()) {
        if (s[i] != '/') {
            stack += s[i];
        } else {
            result.emplace_back(stack);
            stack.clear();
        }
    }
    if (!stack.empty()) result.emplace_back(stack);
    return result;
}

// 処理内容
int main() {

    string s;
    while (cin >> s, s != "#") {
        
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        vector<string> tbl = split(s);
        REP(i, tbl.size()) tbl[i] = parse(tbl[i]);

        tbl[a-1][b-1] = '.';
        tbl[c-1][d-1] = 'b';

        REP(i, tbl.size()) tbl[i] = jfenize(tbl[i]);

        ll h = tbl.size();
        REP(i, h) cout << tbl[i] << "/\n"[i == h-1];

    }
    
}
