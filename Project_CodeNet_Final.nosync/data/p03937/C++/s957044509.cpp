#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

int main() {
    int h, w, ans = 0; cin >> h >> w;
    char f[8][8]; rep(i, h) rep(j, w) { cin >> f[i][j]; if (f[i][j] == '#') ans++; }
    if (ans == h + w - 1) { cout << "Possible" << endl; }
    else { cout << "Impossible" << endl; }
    return 0;
}
