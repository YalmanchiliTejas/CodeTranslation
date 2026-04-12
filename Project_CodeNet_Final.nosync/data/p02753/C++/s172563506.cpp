#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int flag1 = 0, flag2 = 0;
    for (auto x : s) {
        if (x == 'A') flag1 = 1;
        else flag2 = 1;
    }
    if (flag1 && flag2)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
}
