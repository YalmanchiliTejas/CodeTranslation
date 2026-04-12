#include <bits/stdc++.h>
using namespace std;
int h, w, ans;
int main (void) {
    scanf ("%d %d", &h, &w);
    for (int i = 1; i <= h; ++i) {
        getchar ();
        for (int j = 1; j <= w; ++j) {
            char ch = getchar ();
            if (ch == '#') ++ans;
        }
    }
    puts ((ans == h + w - 1) ? "Possible\r\n" : "Impossible\r\n");
}