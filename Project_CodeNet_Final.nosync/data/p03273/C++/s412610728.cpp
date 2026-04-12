#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string multichar(char c, int n) {
    string ret;
    rep(i,n) {
        ret += c;
    }
    return ret;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> ans;
    int count_white[w] = {};
    rep(i,h) {
        string s;
        cin >> s;
        bool allwhite = true;
        rep(j,w) {
            if (s[j] == '.') count_white[j]++;
            else allwhite = false;
        }
        if (!allwhite) ans.push_back(s);
    }
    bool white_column[w] = {};
    rep(i,w) {
        if (count_white[i] == h) {
            white_column[i] = true;
        }
    }
    rep(i,ans.size()) {
        rep(j,w) {
            if (white_column[j]) continue;
            else cout << ans[i][j];
        }
        cout << endl;
    }
}