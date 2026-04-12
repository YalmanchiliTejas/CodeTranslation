#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;

    int c[50][26] = {};

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;

        for (int j = 0; j < s.size(); ++j) {
            ++c[i][s[j] - 'a'];
        }
    }

    int count[26];
    for (int i = 0; i < 26; ++i) {
        count[i] = INF;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            count[j] = min(count[j], c[i][j]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            cout << (char)('a' + i);
        }
    }

    cout << endl;
}