#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    string left = "qwert asdfg zxcvb";
    string right = "yuiop hjkl nm";
    map<char, bool> isLeft;
    for (char& c : left) isLeft[c] = true;
    for (char& c : right) isLeft[c] = false;

    while (true) {
        string s; cin >> s;
        if (s == "#") break;
        int n = s.length();
        vector<bool> a(n);
        for (int i = 0; i < n; i++) a[i] = isLeft[s[i]];
        int cnt = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] != a[i + 1]) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
