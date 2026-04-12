/**
 *    author:  FromDihPout
 *    created: 2020-06-25
**/

#include <bits/stdc++.h>
using namespace std;


bool check(string s, vector<bool> &a, int n) {
    for (int i = 1; i < n - 1; i++) {
        if ((a[i] && s[i] == 'o') || (!a[i] && s[i] == 'x')) {
            a[i + 1] = a[i - 1];
        }
        else {
            a[i + 1] = !a[i - 1];
        }
    }
    
    bool valid;
    if ((a[0] && s[0] == 'o') || (!a[0] && s[0] == 'x')) {
        valid = a[n - 1] == a[1];
    }
    else {
        valid = a[n - 1] != a[1];
    }
    
    if (!valid) return false;
    
    if ((a[n-1] && s[n-1] == 'o') || (!a[n-1] && s[n-1] == 'x')) {
        valid = a[n - 2] == a[0];
    }
    else {
        valid = a[n - 2] != a[0];
    }
    return valid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<pair<bool, bool>> possibilities =
    {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    vector<bool> a(n);
    for (auto p : possibilities) {
        a[0] = p.first;
        a[1] = p.second;
        if (check(s, a, n)) {
            for (int i = 0; i < n; i++) {
                if (a[i])
                    cout << 'S';
                else
                    cout << 'W';
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    
    return 0;
}