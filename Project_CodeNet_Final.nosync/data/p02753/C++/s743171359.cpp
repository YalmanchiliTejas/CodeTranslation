#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    sort(s.begin(), s.end());
    if (s.front() == s.back()) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}