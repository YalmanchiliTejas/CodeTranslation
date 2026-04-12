#include <bits/stdc++.h>
using namespace std;

int to_number(char c) {
    if (c == 'A') return 14;
    if (c == 'K') return 13;
    if (c == 'Q') return 12;
    if (c == 'J') return 11;
    if (c == 'T') return 10;
    return c - '0';
}

bool win(string a, string b, char trump, char led) {
    if (a[1] == trump && b[1] != trump) return true;
    if (a[1] != trump && b[1] == trump) return false;
    if (a[1] == led && b[1] != led) return true;
    if (a[1] != led && b[1] == led) return false;
    if (to_number(a[0]) > to_number(b[0])) return true;
    return false;
}

int main() {
    char trump;
    while (cin >> trump) {
        if (trump == '#') break;

        string card[4][13];
        for (int i=0; i<4; ++i) {
            for (int j=0; j<13; ++j) {
                cin >> card[i][j];
            }
        }

        int last = 0, ns = 0, ew = 0;
        for (int i=0; i<13; ++i) {
            char led = card[last][i][1];
            int k = 0;
            string t = card[0][i];
            for (int j=1; j<4; ++j) {
                if (win(card[j][i], t, trump, led)) {
                    k = j;
                    t = card[j][i];
                }
            }
            if (k == 0 || k == 2) ns ++;
            else ew ++;
            last = k;
        }

        if (ns > ew) cout << "NS " << ns-6 << endl;
        else cout << "EW " << ew-6 << endl;
    }
    return 0;
}
