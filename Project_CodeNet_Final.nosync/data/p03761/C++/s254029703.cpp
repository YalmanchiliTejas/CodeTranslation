#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

string f(char c, int n) {
    string ret;
    rep(i,n) ret.push_back(c);
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> alp(n, vector<int> (26, 0));
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,s.size()) alp[i][s[j]-'a']++;
    }
    string res;
    rep(i,26) {
        int cnt = 1e6;
        rep(j,n) cnt = min(cnt, alp[j][i]);
        string t = f((char)(i+'a'), cnt);
        res += t;
    }
    cout << res << endl;
    return 0;
}