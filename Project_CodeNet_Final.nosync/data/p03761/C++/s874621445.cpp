#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;  cin >> n;
    string s;
    int ans[26];
    for (int i = 0; i < 26; i++)
        ans[i] = 30;

    for (int i = 0; i < n; i++) {
        cin >> s;
        int cnt[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            ans[i] = min(cnt[i], ans[i]);
        }
    }

    string t;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < ans[i]; j++) {
            char c = 'a' + i;
            t.push_back(c);
        }
    }

    cout << t << endl;
    return 0;
}