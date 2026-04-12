#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count[50][26] = {};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            count[i][s[j] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        int minCnt = 100;
        for (int j = 0; j < n; j++) {
            minCnt = min(minCnt, count[j][i]);
        }
        for (int j = 0; j < minCnt; j++) {
            cout << char('a' + i);
        }
    }
    cout << endl;

    return 0;
}