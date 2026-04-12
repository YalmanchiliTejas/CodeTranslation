#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    vector<int> common(26, INT_MAX);

    for (int i = 0; i < N; i++) {
        vector<int> cur(26, 0);
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            cur[c - 'a'] += 1;
        }

        for (int k = 0; k < 26; k++) {
            common[k] = min(common[k], cur[k]);
        }
    }

    string ans;
    for (int l = 0; l < 26; l++) {
        if (common[l] > 0) {
            ans += string(common[l], 'a' + l);
        }
    }
    cout << ans << endl;
    return 0;
}
