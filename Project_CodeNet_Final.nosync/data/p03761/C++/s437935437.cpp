#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> extracted(26, 50*50+1);

    for (int i = 0; i < n; ++i) {
        string S; cin >> S;
        vector<int> cnt(26);
        for (auto& s : S) cnt[s - 'a']++;
        for (int j = 0; j < 26; ++j) {
            extracted[j] = min(extracted[j], cnt[j]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < extracted[i]; ++j) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;

    return 0;
}