#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];

    vector<int> cnt(26);
    string s = S[0];
    for (int i = 0; i < s.size(); i++)
        cnt[s[i] - 'a']++;

    for (int i = 1; i < n; i++) {
        string t = S[i];
        vector<int> c(26);
        for (int j = 0; j < t.size(); j++)
            c[t[j] - 'a']++;
        for (int j = 0; j < 26; j++)
            cnt[j] = min(cnt[j], c[j]);
    }

    string res = "";
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            for (int j = 0; j < cnt[i]; j++) {
                res += i + 'a';
            }
        }
    }
    cout << res << endl;
    return 0;
}