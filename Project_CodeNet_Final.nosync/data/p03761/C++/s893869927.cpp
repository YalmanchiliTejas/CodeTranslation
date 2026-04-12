#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    map<char, int>mp;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        map<char, int> m;
        for (int j = 0; j < s.size(); j++) {
            m[s[j]]++;
        }
        for (int j = 0; j < alphabet.size(); j++) {
            if (i == 0) {
                mp[alphabet[j]] = m[alphabet[j]];
            } else {
                mp[alphabet[j]] = min(mp[alphabet[j]], m[alphabet[j]]);
            }
        }
    }

    string ans = "";
    for (int i = 0; i < alphabet.size(); i++) {
        if (mp[alphabet[i]] > 0) {
            for (int j = 0; j < mp[alphabet[i]]; j++) {
                ans += alphabet[i];
            }
        }
    }
    cout << ans << endl;
}
