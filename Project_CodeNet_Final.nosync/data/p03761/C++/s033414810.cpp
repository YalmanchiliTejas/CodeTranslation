#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    int count[n][26];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            count[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            count[i][s[j] - 'a']++;
        }
    }
    int res[26];
    for (int i = 0; i < 26; i++) {
        res[i] = 100;
        for (int j = 0; j < n; j++) {
            res[i] = min(res[i], count[j][i]);
        }
    }
    string ans;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < res[i]; j++) {
            ans.push_back(i + 'a');
        }
    }
    cout << ans << endl;
    return 0;
}
