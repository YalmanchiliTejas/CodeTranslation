#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
template<class T=int> inline T toint(string s) { T r; istringstream iss(s); iss >> r; return r; }

int main() {
    string s; cin >> s;
    int n = s.length();
    int cnt = 0;
    auto check = [&](int p, int len) {
        int val = toint(s.substr(p, len));
        if (len > 1 && s[p] == '0') return false;
        return 0 <= val && val <= 255;
    };
    #define rep(i) for (i = 1; i <= 3; i++)
    vector<int> len(4);
    rep(len[0]) rep(len[1]) rep(len[2]) rep(len[3]) {
        if (len[0] + len[1] + len[2] + len[3] != n) continue;
        int p = 0;
        bool ok = true;
        for (int l: len) ok &= check(p, l), p += l;
        cnt += ok;
    }
    cout << cnt << endl;
    return 0;
}

