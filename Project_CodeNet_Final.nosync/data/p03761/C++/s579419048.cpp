#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> strs(n);
    vector<int> alphs(26, INT_MAX);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            char srch_alph = (char)('a' + j);
            int cnt = 0;
            for (int k = 0; k < strs[i].size(); k++) {
                if (strs[i][k] == srch_alph) {
                    cnt++;
                }
            }
            alphs[j] = min(cnt, alphs[j]);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alphs[i]; j++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;

    return 0;
}