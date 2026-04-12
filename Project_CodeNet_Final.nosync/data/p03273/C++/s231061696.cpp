#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;
int main() {
    fastIO;
    int h, w;
    cin >> h >> w;
    vector<vector<char>> cells(h);

    rep(i, h) {
        rep(j, w) {
            char c;
            cin >> c;
            cells.at(i).push_back(c);
        }
    }

    vector<bool> hi(h);
    vector<bool> wi(w);
    fill(hi.begin(), hi.end(), true);
    fill(wi.begin(), wi.end(), true);

    // trace row
    rep(i, h) {
        bool removable = true;
        rep(j, w) {
            if (cells.at(i).at(j) == '#')
                removable = false;
        }
        if (removable == true) {
            hi.at(i) = false;
        }
    }

    // trace col
    rep(j, w) {
        bool removable = true;
        rep(i, h) {
            if (cells.at(i).at(j) == '#') {
                removable = false;
            }
        }
        if (removable == true) {
            wi.at(j) = false;
        }
    }

    // output
    rep(i, h) {
        bool newLine = false;
        rep(j, w) {
            if (hi.at(i) == true && wi.at(j) == true) {
                cout << cells.at(i).at(j);
                newLine = true;
            }
        }
        if (newLine)
            cout << endl;
    }
}