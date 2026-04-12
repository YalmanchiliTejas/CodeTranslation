#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 2) == "AC") {
            cout << "Yes\n"; return 0;
        }
    }
    cout << "No\n";
    return 0;
}