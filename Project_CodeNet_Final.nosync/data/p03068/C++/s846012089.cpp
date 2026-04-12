#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    char t = s[k-1];
    for (auto& v : s) {
        if (v != t) v = '*';
    }
    cout << s << endl;
}