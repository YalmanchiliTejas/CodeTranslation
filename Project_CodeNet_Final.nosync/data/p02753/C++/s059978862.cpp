#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string res = "Yes";
    if (s.at(0) == s.at(1) && s.at(1) == s.at(2)) res = "No";

    cout << res << endl;

    return 0;
}
