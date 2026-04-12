#include <bits/stdc++.h>
using namespace std;
int main () {
    int h, w;
    cin >> h >> w;
    int k = 0;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        if (s[k] != '#') {
            puts("Impossible");
            return 0;
        }
        for (int j = k; j < w; j++) {
            if (s[j] == '#') {
                s[j] = '.';
                k = j;
            }
            else {
                break;
            }
        }
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') {
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");
}