#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n;
    cin >> n;
    string s[n];
    int cnt[n][26];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            cnt[i][s[i][j] - 'a']++;
        }
    }
    string ans = "";
    for (int i = 0; i < 26; i++) {
        int mn = 1e9;
        for (int j = 0; j < n; j++) {
            mn = min(mn, cnt[j][i]);
        }
        for (int j = 0; j < mn; j++) {
            ans += ('a' + i);
        }
    }

    cout << ans << endl;


    return 0;
}
