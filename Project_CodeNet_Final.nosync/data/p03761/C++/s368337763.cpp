#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n;
vector<string> s;
map<char,int> flags;

int main() {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        map<char,int> tempflags;
        for (int j = 0; j < s[i].size(); j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (s[i][j] == c) tempflags[c]++;
            }
        }
        if (i == 0) flags = tempflags;
        else {
            for (char c = 'a'; c <= 'z'; c++) {
                flags[c] = min(flags[c], tempflags[c]);
            }
        }
    }

    string ans;
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < flags[c]; i++) {
            ans+=c;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}