#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    vector<string> moji(n);
    for (int i=0; i<n; i++) {
        cin >> moji.at(i);
    }
    vector<int> count(26);
    for (char s='a'; s<='z'; s++) {
        int min = 100000;
        for (string str : moji) {
            int buf = 0;
            for (char c : str) {
                if (c == s) buf++;
            }
            if (buf < min) min = buf;
        }
        count.at(s-'a') = min;
    }
    for (int i=0; i<26; i++) {
        char put = 'a' + i;
        for (int j=0; j<count.at(i); j++) {
            cout << put;
        }
    }
    cout << endl;
    return 0;
}
