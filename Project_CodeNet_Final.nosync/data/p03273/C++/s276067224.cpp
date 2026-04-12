#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<bool> bh(h), bw(w);
    vector< vector<char> > a(h, vector<char>(w));
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
        cin >> a.at(i).at(j);
        if (a.at(i).at(j) - '.') {
            bh.at(i) = 1;
            bw.at(j) = 1;
        }
    }
    for (int i = 0; i < h; ++i) {
        if (bh.at(i)) {
            for (int j = 0; j < w; ++j) if (bw.at(j)) cout << a.at(i).at(j);
            cout << endl;
        }
    }
    return 0;
}
