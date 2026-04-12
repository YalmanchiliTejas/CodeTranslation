#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int h = 0, w = 0;
    cin >> h >> w;
    int cnt = 0;
    char buf = 0;
    for (int i=0; i<h*w; i++) {
        cin >> buf;
        if (buf == '#') {
            cnt++;
        }
    }
    if (cnt == h+w-1) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    return 0;
}
