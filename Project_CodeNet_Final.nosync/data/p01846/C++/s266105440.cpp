#include <iostream>
#include <vector>
using namespace std;

string expand(string s) {
    string ret = "";
    for (auto c : s) {
        if ('0' < c && c <= '9') {
            for (int i = 0; i < c - '0'; i++) {
                ret += '.';
            }
        } else {
            ret += c;
        }
    }
    return ret;
}

string compress(string s) {
    string ret = "";
    int cnt = 0;
    for (auto c : s) {
        if (c == '.') cnt++;
        else {
            if (cnt) {
                ret += (cnt + '0');
                cnt = 0;
            }
            ret += c;
        }
    }
    if (cnt) ret += (cnt + '0');
    return ret;
}

int main() {
    string s;
    while (cin >> s, s != "#") {
        vector<string> mp;

        int delim_idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                mp.push_back(expand(s.substr(delim_idx, i - delim_idx)));
                delim_idx = i + 1;
            }
        }
        mp.push_back(expand(s.substr(delim_idx)));

        int a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        mp[a][b] = '.';
        mp[c][d] = 'b';
        for (int i = 0; i < mp.size(); i++) {
            if (i) cout << '/';
            cout << compress(mp[i]);
        }
        cout << endl;
    }
}

