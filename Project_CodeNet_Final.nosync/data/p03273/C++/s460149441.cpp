#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> s;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s.push_back(t);
    }
    vector <int> rem(n, 0);
    for (int i = 0; i < n; i++) {
        int x = count(s[i].begin(), s[i].end(), '.');
        if (x == m) {
            rem[i] = true;
        }
    }
    vector <string> a;
    for (int i = 0; i < n; i++) {
        if (!rem[i]) {
            a.push_back(s[i]);
        }
    }
    vector <int> musor(m, 0);
    for (int i = 0; i < m; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            x += (s[j][i] == '.');
        }
        if (x == n) {
            musor[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        bool any = false;
        for (int j = 0; j < m; j++) {
            if (rem[i] || musor[j]) {
                continue;
            }
            any = 1;
            cout << s[i][j];
        }
        if (any) {
            cout << '\n';   
        }
    }
    return 0;
}