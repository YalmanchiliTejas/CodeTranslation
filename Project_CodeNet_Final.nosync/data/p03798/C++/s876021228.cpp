#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s, s += s[0];
    vector<string> init { "SS", "SW", "WS", "WW" };
    for (auto& e : init) {
        for (int i = 1; i <= n; i++) {
            auto b = e[i] == 'S' ? 'o' : 'x';
            auto p = s[i] == b ? 'S' : 'W';
            e += e[i-1] == p ? 'S' : 'W';
        }
        if (e.substr(0, 2) == e.substr(n, 2)) {
            cout << e.substr(0, n) << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
