#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[26] = {};
    for (int i = 0; i < 26; i++) {
        a[i] = 50;
    }

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;

        int b[26] = {};
        for (int j = 0; j < s.size(); j++) {
            b[s[j] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            a[j] = min(a[j], b[j]);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << (char)('a' + i);
        }
    }

    cout << endl;

    return 0;
}
