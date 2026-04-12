#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans="No";

    for (int i=1; i<3; i++) {
        if (s.at(i-1) != s.at(i)) ans = "Yes";
    }

    cout << ans << endl;
}