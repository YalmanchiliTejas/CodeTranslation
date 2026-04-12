#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vt(26, 3000);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 26; ++j) {
            vt[j] = min(vt[j], (int) count(s.begin(), s.end(), 'a' + j));
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < vt[i]; ++j) {
            cout << char(i + 'a');
        }
    }

    cout << endl;
    return 0;
}