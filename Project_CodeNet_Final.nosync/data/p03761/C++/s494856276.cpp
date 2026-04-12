#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> temp(26, 0), cnt(26, 100);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        temp = vector<int>(26, 0);
        for (int j = 0; j < (int) s.size(); ++j) {
            ++temp[s[j] - 'a'];
        }

        for (int j = 0; j < 26; ++j) {
            cnt[j] = min(cnt[j], temp[j]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << (char)('a' + i);
        }
    }

    cout << endl;
}