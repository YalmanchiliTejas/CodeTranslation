#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i-1]) ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
