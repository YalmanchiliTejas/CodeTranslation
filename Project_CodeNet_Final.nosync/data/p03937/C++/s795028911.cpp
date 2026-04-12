#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (a[i][j+1] == '#' && a[i+1][j] == '#') {
                cout << "Impossible" << endl;
                return 0;

            }
        }
    }
    cout << "Possible" << endl; 
}
