#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P_ii;
typedef pair<string, int> P_si;

int main() {
    int n;
    cin >> n;
    vector<string> S;
    map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        mp[c] = INT32_MAX;
    }

    for (int i = 0; i < n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            int cnt = count(S[i].begin(), S[i].end(), c);
            mp[c] = min(mp[c], cnt);
        }
    }
    string ans;
    for (char c = 'a'; c <= 'z'; c++) {
        if (mp[c] == INT32_MAX) continue;
        for (int i = 0; i < mp[c]; ++i) {
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}
