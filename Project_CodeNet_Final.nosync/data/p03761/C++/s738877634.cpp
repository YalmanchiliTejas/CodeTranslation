#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[n][256] = {};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[i][c]++;
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int l = 51;
        for (int i = 0; i < n; i++) {
            l = min(cnt[i][c], l);
        }
        for (int i = 0; i < l; i++) {
            cout << c;
        }
    }
}