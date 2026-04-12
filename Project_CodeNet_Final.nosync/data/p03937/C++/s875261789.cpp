#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    int h, w, cnt = 0;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            if (c == '#') ++cnt;
        }
    }

    if (cnt == h + w - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}