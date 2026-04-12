#include "bits/stdc++.h"

using namespace std;

void Main() {
    int n;
    cin >> n;
    vector<vector<int>> chars(n, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            chars[i][s[j] - 'a'] += 1;
        }
    }
    string ans = "";
    for (int j = 0; j < 26; ++j) {
        int minOfThis = 1000000000;
        for (int i = 0; i < n; ++i) {
            minOfThis = min(minOfThis, chars[i][j]);
        }
        for (int k = 0; k < minOfThis; ++k) {
            ans += ('a' + j);
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
