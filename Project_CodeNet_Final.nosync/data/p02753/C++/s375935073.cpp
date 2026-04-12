#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    //bool a = false, b = false;
    int a = 0, b = 0;

    for (int i = 0; i < s.size(); i++) {
        if ('A' == s[i]) a++;
        if ('B' == s[i]) b++;
    }

    if (a > 0 && b > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}