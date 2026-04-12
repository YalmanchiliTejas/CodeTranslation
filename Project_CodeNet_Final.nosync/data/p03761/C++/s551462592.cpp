#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using Int = int64_t;
int main() {
    Int n;
    cin >> n;
    vector<int> min(26, 50);
    string S;
    for (int i = 0; i < n; i++) {
        cin >> S;
        vector<int> cnt(26);
        for (char c : S) cnt[c - 'a']++;
        for (int j = 0; j < 26; j++) if (cnt[j] < min[j]) min[j] = cnt[j];
    }
    bool exist = false;
    for (int i = 0; i < 26; i++) {
        if (min[i] > 0) {
            exist = true;
            cout << string(min[i], (char)(i + 'a'));
        }
    }
    if (exist) cout << endl;
}
