#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

string s;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s.substr(i, 2) == "AC") {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
