#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> charn(n, vector<int>(26));
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (char j: s) {
            charn[i][j - 'a']++;;
        }
    }
    vector<int> ans(26);
    for (int i=0; i<26; ++i) {
        int minn = 100;
        for (int j=0; j<n; ++j) {
            minn = min(minn, charn[j][i]);
        }
        for (int j=0; j<minn; ++j) cout << (char)('a' + i);
    }
    cout << endl;
}