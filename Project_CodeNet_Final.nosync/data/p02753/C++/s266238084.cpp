#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
