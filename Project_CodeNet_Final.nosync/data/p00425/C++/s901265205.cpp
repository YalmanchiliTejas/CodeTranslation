#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    string s;
    while (cin >> n, n) {
        int dice[] = {1, 2, 3, 4, 5, 6}, a, b, c, d, ans = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == "North")
                a = 0, b = 1, c = 5, d = 4;
            else if (s == "East")
                a = 0, b = 3, c = 5, d = 2;
            else if (s == "West")
                a = 0, b = 2, c = 5, d = 3;                
            else if (s == "South")
                a = 0, b = 4, c = 5, d = 1;
            else if (s == "Right")
                a = 1, b = 2, c = 4, d = 3;
            else
                a = 1, b = 3, c = 4, d = 2;

            swap(dice[a], dice[b]);
            swap(dice[b], dice[c]);
            swap(dice[c], dice[d]);

            ans += dice[0];
        }

        cout << ans + 1 << endl;
    }

    return 0;
}
