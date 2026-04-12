#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int n;
    cin >> n;
    string s;
    map<char, int> alphabet;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int t = s.size();
        map<char, int> mp;
        for (int j = 0; j < t; j++) {
            for (int k = 0; k < 26; k++) {
                char c = 'a' + k;
                if (s[j] == c) mp[c]++;
            }
        }
        if (i == 0) {
            alphabet = mp;
            continue;
        }
        for (int j = 0; j < 26; j++) {
            char c = 'a' + j;
            alphabet[c] = min(alphabet[c], mp[c]);
        }
    }
    for (auto x : alphabet) {
        for (int i = 0; i < x.second; i++) cout << x.first;
    }
    cout << endl;
}