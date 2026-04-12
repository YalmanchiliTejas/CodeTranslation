#include <bits/stdc++.h>
using namespace std;

bool f(bool a, bool b) {
    if (a && !b) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<bool> hoge(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        hoge[i] = c == 'T';
    }

    bool ans = f(hoge[0], hoge[1]);
    for (int i = 2; i < n; i++) {
        ans = f(ans, hoge[i]);
    }

    cout << (ans ? "T" : "F") << endl;
}
