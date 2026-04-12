#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool a = false, b = false;
    for(char c : s) {
        a |= (c == 'A');
        b |= (c == 'B');
    }
    cout << (a && b ? "Yes\n" : "No\n");
}