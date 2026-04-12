#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define all(c) c.begin(),c.end()
#define sz(c) ((int)c.size())
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

string jfen(vector<string> board) {
    int n = sz(board);
    string ret;
    rep(i, 0,n) {
        int cnt = 0;
        string line;
        rep(j, 0, sz(board[i])) {
            if (board[i][j] == '.') {
                cnt++;
            } else {
                if (cnt) line += cnt + '0';
                cnt = 0;
                line += 'b';
            }
        }
        if (cnt) line += cnt + '0';
        ret += line;
        if (i != n - 1) ret += '/';
    }
    return ret;
}
vector<string> unjfen(string s) {
    vector<string> ret;
    auto to_line = [](string line) {
        string r;
        rep(i, 0, sz(line)) {
            if (line[i] == 'b') {
                r += "#";
            } else {
                r += string(line[i] - '0', '.');
            }
        }
        return r;
    };
    s += "/";
    string tmp;
    rep(i, 0, sz(s)) {
        if (s[i] == '/') {
            ret.push_back(to_line(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    return ret;
}

signed main() {
    while (1) {
        string s;
        cin >> s;
        if (s == "#") break;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        auto board = unjfen(s);
        swap(board[a][b], board[c][d]);
        auto ans = jfen(board);
        cout << ans << endl;
    }
}

