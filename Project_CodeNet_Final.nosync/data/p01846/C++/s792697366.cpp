#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;
using ll = long signed long;

vector<string> jfen2table(const string &jfen) {
    string jeffen = jfen + "/";
    vector<string> table;
    string q;
    for (const char &c : jeffen) {
        if (c == '/') {
            table.push_back(q);
            q = "";
        } else if (c == 'b') {
            q += 'b';
        } else {
            q += string(c - '0', '.');
        }
    }
    return table;
}

string table2jfen(const vector<string> &table) {
    string jfen = "";
    for (const string &line : table) {
        for (const char &c : line) {
            if (c == '.') {
                if (!jfen.empty() && '1' <= jfen.back() && jfen.back() < '9') {
                    jfen.back()++;
                } else {
                    jfen += "1";
                }
            } else {
                jfen += "b";
            }
        }
        jfen += "/";
    }
    jfen.pop_back();
    return jfen;
}

int main() {

    string ans = "";

    for (string s; cin >> s, (s != "#"); ) {

        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        auto tbl = jfen2table(s);
        tbl[a][b] = '.';
        tbl[c][d] = 'b';

        ans += table2jfen(tbl);
        ans += "\n";

    }

    cout << ans;

}
