#include<iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int table[50][26] = {0};
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            table[i][s[j] - 'a']++;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (table[i][j] > table[i - 1][j]) {
                table[i][j] -= table[i][j] - table[i - 1][j];
            }
        }
    }
    /*
    for (int i = 0; i < 26; ++i) {
        cout << table[n - 1][i] << " ";
        if (i == 25) cout << endl;
    }*/
    for (int i = 0; i < 26; ++i) {
        while (table[n - 1][i]) {
            table[n - 1][i]--;
            cout << (char)('a' + i);
        }
    }
    cout << endl;
    return 0;
}
