#include <iostream>
using namespace std;

int main() {
    int h, w, cnt = 0;
    char a[10][10];
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = 0;
            cin >> a[i][j];
            if (a[i][j] == '#') cnt++;
        }
    }

    if (cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}