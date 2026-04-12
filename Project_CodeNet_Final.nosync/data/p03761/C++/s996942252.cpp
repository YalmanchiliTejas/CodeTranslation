#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    vector<vector<int>> num(26, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            char c = S[i][j];
            num[c - 'a'][i]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        int r = *min_element(num[i].begin(), num[i].end());
        for (int j = 0; j < r; j++) {
            cout << (char)('a' + i);
        }
    }

    cout << endl;
    return 0;
}