#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool a = false, b = false;

    string s;   cin >> s;

    for(auto &c : s) {
        if(c == 'A') {
            a = true;
        } else {
            b = true;
        }
    }

    if(!a || !b) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    return 0;
}
