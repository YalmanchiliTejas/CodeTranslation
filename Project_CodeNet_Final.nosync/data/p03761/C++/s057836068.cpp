#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<map<char, int>> smap(n);
    rep(i, n) {
        string s; cin >> s;
        for (auto c : s) {
            smap[i][c]++;
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int count = 100;
        rep(i, n) {
            count = min(count, smap[i][c]);
        }
        if (count != 0) {
            rep(j, count) {
                cout << c;
            }
        }
    }
    cout << endl;
}