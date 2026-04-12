#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (char& ch : s) cnt += ch == '#';
    }
    if (cnt == h + w - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}