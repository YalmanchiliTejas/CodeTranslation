#include <bits/stdc++.h>
using namespace std;

vector<string> fromJfen(const string s) {
    vector<string> res;
    string t = ""; // row's string
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '/') continue;
        t += s[i];
        if (i == (int)s.size() - 1 || s[i + 1] == '/') {
            string r = "";
            for (int j = 0; j < (int)t.size(); ++j) {
                if (t[j] == 'b') {
                    r += "b";
                    continue;
                } else if ('0' < t[j] && t[j] <= '9') {
                    for (int k = 0; k < t[j] - '0'; ++k) r += ".";
                }
            }
            res.push_back(r);
            t = "";
        }
    }
    return res;
}

string toJfen(const vector<string> &vs) {
    string res = "";
    for (int i = 0; i < (int)vs.size(); ++i) {
        if (i != 0) res += "/";
        int cnt = 0;
        for (int j = 0; j < (int)vs[i].size(); ++j) {
            if (vs[i][j] == '.') {
                cnt++;
                if (j == (int)vs[i].size() - 1 || vs[i][j + 1] == 'b') {
                    res += char('0' + cnt);
                    cnt = 0;
                }
            } else if (vs[i][j] == 'b') {
                res += "b";
            }
        }
    }
    return res;
}

int main() {
    string S;
    while (cin >> S) {
        if (S == "#") break;
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        vector<string> vs = fromJfen(S);
        vs[a - 1][b - 1] = '.';
        vs[c - 1][d - 1] = 'b';
        cout << toJfen(vs) << endl;
    }
    return 0;
}
