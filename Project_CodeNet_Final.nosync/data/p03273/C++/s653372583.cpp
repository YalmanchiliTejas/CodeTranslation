#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> M(h);
    for (int i = 0; i < h; ++i) {
        cin >> M[i];
    }

    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (M[i][j] == '#') {
                row[i] = col[j] = true;
            }
        }
    }

    vector<string> res;
    for (int i = 0; i < h; ++i) {
        string s;
        for (int j = 0; j < w; ++j) {
            if (row[i] && col[j]) {
                s += M[i][j];
            }
        }
        if (s.length() > 0) {
            res.push_back(s);
        }
    }

    for (auto& s : res) {
        cout << s << "\n";
    }
    return 0;
}