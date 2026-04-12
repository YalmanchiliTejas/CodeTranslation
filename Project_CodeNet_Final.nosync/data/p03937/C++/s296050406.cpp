#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int r = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char a;
            cin >> a;
            r += a == '#';
        }
    }

    cout << (r == h + w - 1 ? "Possible" : "Impossible") << endl;

    return 0;
}