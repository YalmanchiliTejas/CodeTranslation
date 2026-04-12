#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> cmin(26, 1e9+7);
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        vector<int> c(26, 0);
        cin >> s;
        int slen = s.length();
        for(int i = 0; i < slen; ++i) {
            c.at(s.at(i) - 97)++;
        }
        for(int i = 0; i < 26; ++i) {
            cmin.at(i) = min(cmin.at(i), c.at(i));
        }
    }

    char cnow = 'a';
    for(int i = 0; i < 26; ++i) {
        int clen = cmin.at(i);
        for(int j = 0; j < clen; ++j) {
            cout << cnow;
        }
        cnow++;
    }
}