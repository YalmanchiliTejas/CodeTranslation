#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1000;

int main() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    int t[26];
    for (int i = 0; i < 26; i++) t[i] = inf;
    for (int i = 0; i < n; i++) {
        int u[26];
        for (int j = 0; j < 26; j++) u[j] = 0;
        for (int j = 0; j < s[i].length(); j++) {
            int k = s[i][j] - 'a';
            u[k]++;
        }
        for (int j = 0; j < 26; j++) {
            t[j] = min(t[j], u[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < t[i]; j++) {
            cout << (char) ('a' + i);
        }
    }
    cout << endl;
    return 0;
}