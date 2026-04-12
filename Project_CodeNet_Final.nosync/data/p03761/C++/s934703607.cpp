//
// C - 怪文書 / Dubious Document
//

#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int c1['z' + 1];
    fill(c1, c1 + 'z' + 1, 51);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c2['z' + 1] = {0};
        for (char c : s) {
            c2[c]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            c1[c] = min(c1[c], c2[c]);
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < c1[c]; i++) {
            cout << c;
        }
    }
    cout << endl;
}