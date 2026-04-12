#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v[27];
    rep(i, n) {
        string s;
        cin >> s;
        for (char c = 'a'; c <= 'z'; c++) {
            int cnt = count(s.begin(), s.end(), c);
            v[c - 'a'].push_back(cnt);
        }
    }

    rep(i, 26) {
        sort(v[i].begin(), v[i].end());
        if (v[i][0] != 0) {
            char c = 'a' + i;
            rep(j, v[i][0]) cout << c;
        }
    }
    cout << endl;

    return 0;
}
