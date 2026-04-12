#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> alpha(n, vector<int>(26, 0)); // i番目の文字列に含まれる各アルファベットの個数
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, (int)s.size()) {
            alpha[i][s[j]-'a']++;
        }
    }
    string ans;
    rep(j, 26) {
        int _min = 50;
        rep(i, n) {
            _min = min(_min, alpha[i][j]);
        }
        rep(i, _min) {
            ans.push_back('a'+j);
        }
    }
    cout << ans << endl;
}