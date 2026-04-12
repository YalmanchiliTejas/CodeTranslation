#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt[26][50] = {};
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (auto c : s) {
            cnt[c - 'a'][i]++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        int k = *min_element(&cnt[i][0], &cnt[i][n]);
        while (k--)
            cout << (char)('a' + i);
    }
    cout << endl;

    return 0;
}