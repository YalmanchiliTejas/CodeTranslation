#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> vs;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    vector<int> vh(h, 0), vw(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vs[i][j] == '#') {
                vh[i] = 1;
                vw[j] = 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        int flag = 0;
        for (int j = 0; j < w; j++) {
            if (vh[i] == 1 && vw[j] == 1) {
                cout << vs[i][j];
                flag = 1;
            }
        }
        if (flag) cout << endl;
    }
}
