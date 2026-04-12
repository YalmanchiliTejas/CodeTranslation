#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    for (int i = 1 ; i < s.size() ; i++) {
        if (s[i - 1] != s[i]) {
            cout << "Yes\n";
            exit(0);
        }
    }
    cout << "No\n";

}
