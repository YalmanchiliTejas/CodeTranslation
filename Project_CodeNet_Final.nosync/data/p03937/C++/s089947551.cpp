#include <iostream>
#include <string>

using namespace std;

int main() {
    int h, w, pos = 0;
    string a;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> a;
        if (a.at(pos) == '.') {
            cout << "Impossible" << endl;
            return 0;
        }
        for (int i = 0; i < pos; ++i) if (a.at(i) == '#') {
            cout << "Impossible" << endl;
            return 0;
        }
        for (; pos < w; ++pos) if (a.at(pos) == '.') break;
        for (int i = pos; i < w; ++i) if (a.at(i) == '#') {
            cout << "Impossible" << endl;
            return 0;
        }
        --pos;
    }
    cout << "Possible" << endl;
    return 0;
}
